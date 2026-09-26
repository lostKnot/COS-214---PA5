#include <iostream>

#include "CampusComponent.h"
#include "LockedAccessState.h"
#include "NormalAccessState.h"

//---------------------------------------------------------

void LockedAccessState::lock(CampusComponent* c) {
	
    if (!c) {
            std::cout << "Invalid CampusComponent\n";
            return;
        }

    std::cout << "[LockedAccessState] Componnet: " << c->getName() << " is already locked. \n";
}

//---------------------------------------------------------

void LockedAccessState::unlock(CampusComponent* c) {
	
    if (!c) {
            std::cout << "Invalid CampusComponent\n";
            return;
        }

        std::cout << "[LockedAccessState] Unlocking component: " << c->getName() << "\n";
        c->setAccess(new NormalAccessState());
    delete this;
}

//---------------------------------------------------------

std::string LockedAccessState::getStatus() {
	
    return "State: LockedAccess" ;
}

//---------------------------------------------------------
