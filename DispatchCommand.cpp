#include "DispatchCommand.h"

//---------------------------------------------------------

DispatchCommand::DispatchCommand(ResponseCoordinator* coord, Incident* inc, UnitType u): coordinator(coord), incident(inc), unit(u) {}

//---------------------------------------------------------

void DispatchCommand::execute() {
	
    if (!coordinator || !incident) {
        std::cout << "[DispatchCommand] Error: Missing coordinator or incident reference.\n";
        return;
    }

    std::cout << "[DispatchCommand] Executing dispatch for incident: " << incident->getDescription() << "\n";
    coordinator->dispatch(incident, unit);
}

//---------------------------------------------------------

void DispatchCommand::undo() {
	
    if (!coordinator || !incident) {
        std::cout << "[DispatchCommand] Error: Missing coordinator or incident reference.\n";
        return;
    }

    std::cout << "[DispatchCommand] Undoing dispatch for incident: " << incident->getDescription() << "\n";

    std::cout << "[DispatchCommand] Dispatch recall logged with coordinator.\n";
}

//---------------------------------------------------------
