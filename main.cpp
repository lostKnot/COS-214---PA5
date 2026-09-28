#include <iostream>

#include "Building.h"
#include "AccessPoint.h"
#include "Person.h"
#include "NormalAccessState.h"

#include "LegacyTurnstile.h"
#include "LegacyTurnstileAdapter.h"

#include "OperatorConsole.h"
#include "ControlCentre.h"
#include "SecurityTeam.h"
#include "MedicalResponder.h"

#include "CampusEmergencyFacade.h"

#include "Incident.h"
#include "ReportedState.h"
#include "ActiveResponseState.h"

using namespace std;

int main() {

    cout << " SCENARIO 1: Incident reported, campus locked down, units dispatched \n\n";

    //  Composite: build the campus hierarchy ---
    Building* campus = new Building("Main Campus");
    Building* scienceBlock = new Building("Science Block");
    AccessPoint* frontDoor = new AccessPoint("Science Block Front Door");
    Person* alice = new Person("Alice", "CARD-001");

    frontDoor->setAccess(new NormalAccessState());

    //  Adapter: wrap the legacy turnstile so it satisfies AccessGate ---
    LegacyTurnstile* legacyDevice = new LegacyTurnstile();
    LegacyTurnstileAdapter* adaptedGate = new LegacyTurnstileAdapter(legacyDevice);
    frontDoor->setGate(adaptedGate);

    scienceBlock->add(frontDoor);
    scienceBlock->add(alice);
    campus->add(scienceBlock);

    //  Mediator: response coordinator with registered units ---
    ControlCentre* coordinator = new ControlCentre();
    SecurityTeam* security = new SecurityTeam("Security Team A", coordinator);
    MedicalResponder* medic = new MedicalResponder("Medic Team A", coordinator);
    coordinator->registerUnit(security);
    coordinator->registerUnit(medic);

    // Command: operator console issues/tracks commands ---
    OperatorConsole* console = new OperatorConsole();

    // Facade: simplifies lockdown/resolve for the operator ---
    CampusEmergencyFacade* facade = new CampusEmergencyFacade(campus, console, coordinator);

    // State: incident starts in the Reported state ---
    Incident* incident = new Incident(
        1,
        "Suspicious device reported in Science Block",
        1,
        scienceBlock,
        new ReportedState(),
        coordinator
    );

    cout << "\n-- Facade triggers lockdown: issues Lockdown + Dispatch commands --\n";
    facade->lockdown(scienceBlock, incident);

    cout << "\n-- Incident moves to ActiveResponse now that units are dispatched --\n";
    incident->setState(new ActiveResponseState());
    incident->getStatus();

    cout << "\n-- Incident escalates: State delegates to ResponseCoordinator (Mediator) --\n";
    incident->escalate();

    cout << "\n SCENARIO 2: Emergency resolved, campus unlocked \n\n";

    cout << "Facade resolves the emergency: issues Unlock command, resolves incident\n";
    facade->resolveEmergency(scienceBlock, incident);
    incident->getStatus();

    cout << "\n Operator undoes the last command issued (the unlock) \n";
    console->undoLast();

    cout << "\n Cleanup \n";
    delete facade;
    delete incident;
    delete console;
    delete coordinator;
    delete security;
    delete medic;
    delete campus; // recursively deletes scienceBlock, frontDoor, alice

    return 0;
}