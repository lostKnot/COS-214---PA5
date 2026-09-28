int main() {

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

    
    
    std::cout << "===== Scenario 2 ===== \n";

    
    return 0;
}
    
    
    
    return 0;
}
