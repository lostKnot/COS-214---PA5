#include <iostream>

#include "NormalAccessState.h"
#include "CampusComponent.h"
#include "LockedAccessState.h"

//---------------------------------------------------------

void NormalAccessState::lock(CampusComponent* c) {
	
    if (!c) {
            std::cout << "Invalid CampusComponent\n";
            return;
        }

        std::cout << "[NormalAccessState] Locking component: " << c->getName() << "\n";
        c->setAccess(new LockedAccessState());
    delete this;
}

//---------------------------------------------------------

void NormalAccessState::unlock(CampusComponent* c) {
	
    if (!c) {
            std::cout << "Invalid CampusComponent\n";
            return;
        }

    std::cout << "[NormalAccessState] Componnet: " << c->getName() << " is already unlocked. \n";
}

//---------------------------------------------------------

std::string NormalAccessState::getStatus() {
    
    return "State: NormalAccess" ;
}

//---------------------------------------------------------
