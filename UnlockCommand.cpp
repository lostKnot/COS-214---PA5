#include "UnlockCommand.h"

//---------------------------------------------------------

void UnlockCommand::execute() {
	
    if (!target) {
        std::cout << "[UnlockCommand] Error: Target CampusComponent is null.\n";
        return;
    }

    std::cout << "[UnlockCommand] Executing unlock on: " << target->getName() << "\n";
    target->unlock();
}

//---------------------------------------------------------

void UnlockCommand::undo() {
	
    if (!target) {
        std::cout << "[UnlockCommand] Error: Target CampusComponent is null.\n";
        return;
    }

    std::cout << "[UnlockCommand] Undoing unlock (locking): " << target->getName() << "\n";
    target->lock();
}

//---------------------------------------------------------
