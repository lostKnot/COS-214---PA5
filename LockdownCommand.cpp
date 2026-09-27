#include "LockdownCommand.h"

//---------------------------------------------------------

void LockdownCommand::execute() {
	
    if (!target) {
        std::cout << "[LockdownCommand] Error: Target CampusComponent is null.\n";
        return;
    }

    std::cout << "[LockdownCommand] Executing lockdown on: " << target->getName() << "\n";
    target->lock();
}

//---------------------------------------------------------

void LockdownCommand::undo() {
	
    if (!target) {
        std::cout << "[LockdownCommand] Error: Target CampusComponent is null.\n";
        return;
    }

    std::cout << "[LockdownCommand] Undoing lockdown on: " << target->getName() << "\n";
    target->unlock();
}

//---------------------------------------------------------
