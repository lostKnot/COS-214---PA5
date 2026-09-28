#include <iostream>

#include "CampusComponent.h"
#include "Building.h"
#include "AccessPoint.h"
#include "Person.h"
#include "NormalAccessState.h"
#include "LockedAccessState.h"
#include "Incident.h"
#include "ReportedState.h"
#include "AccessGate.h"
#include "LegacyTurnstile.h"
#include "LegacyTurnstileAdapter.h"
#include "Command.h"
#include "OperatorConsole.h"
#include "LockdownCommand.h"
#include "DispatchCommand.h"
#include "ControlCentre.h"
#include "SecurityTeam.h"
#include "MedicalResponder.h"
#include "UnitType.h"

int main() {
    
    //---------------------------------------------------------------------------------
    // Setting up objects for testing
    //---------------------------------------------------------------------------------

    // initialising Campus
    Building* Hat = new Building("Hatfield Campus");
    
    // initialisng places on campus
    Building* Cent = new Building("Centenary");
    Building* IT = new Building("IT Building");
    Building* InfLab = new Building("Informatorium labs");
    Building* Thuto = new Building("Thuto");
    Building* SC = new Building("Student Center");
    Building* BM = new Building("Bookmark");
    Building* Shops = new Building("Shops");
    
    // initialising people
    Person* S = new Person("Sudud","25");
    Person* C = new Person("Christian","24");
    Person* L = new Person("Lizalise","23");
    
    // initialisng access points
    AccessPoint* Pros = new AccessPoint("Prospect St");
    AccessPoint* Lyn = new AccessPoint("Lynwood Rd");

    // sorting the buildings into a hierarchy tree
    InfLab->add(C);
    Cent->add(L);
    BM->add(S);
    
    IT->add(InfLab);
    SC->add(BM);
    SC->add(Shops);
    
    Hat->add(Cent);
    Hat->add(IT);
    Hat->add(Thuto);
    Hat->add(SC);
    Hat->add(Pros);
    Hat->add(Lyn);

    //---------------------------------------------------------------------------------
    
    std::cout << "===== Scenario 1 ===== \n";

    LegacyTurnstile* oldTurnstile = new LegacyTurnstile();
    AccessGate* adaptedGate = new LegacyTurnstileAdapter(oldTurnstile);
    Pros->setGate(adaptedGate);

    Hat->setAccess(new NormalAccessState());
    Pros->setAccess(new NormalAccessState());
    Lyn->setAccess(new NormalAccessState());

    ControlCentre* hub = new ControlCentre();
    SecurityTeam* secAlpha = new SecurityTeam("Security-Alpha", hub);
    MedicalResponder* medBeta = new MedicalResponder("Medical-Beta", hub);

    hub->registerUnit(secAlpha);
    hub->registerUnit(medBeta);

    OperatorConsole console;

    Incident* intrusion = new Incident(101, "Unauthorized breach at IT Building", 4, IT, new ReportedState(), hub);
    std::cout << intrusion->getStatus() << "\n";

    intrusion->escalate();
    std::cout << intrusion->getStatus() << "\n";

    Command* lockCmd = new LockdownCommand(Hat);
    console.issue(lockCmd);

    Command* dispatchCmd = new DispatchCommand(hub, intrusion, UnitType::SECURITY);
    console.issue(dispatchCmd);

    Hat->notify("Lockdown active: Security dispatched to IT Building.");

    intrusion->resolve();
    std::cout << intrusion->getStatus() << "\n";

    console.undoLast();
    console.undoLast();

    delete adaptedGate;
    delete oldTurnstile;
    delete secAlpha;
    delete medBeta;
    delete hub;
    delete intrusion;
    
    //---------------------------------------------------------------------------------
    
    std::cout << "===== Scenario 2 ===== \n";

    
    
    //---------------------------------------------------------------------------------

    Hat->remove(IT);
    Hat->remove(SC);
    delete IT;
    delete SC;
    delete Hat;
    
    return 0;
}
