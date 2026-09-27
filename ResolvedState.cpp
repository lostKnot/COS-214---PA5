#include <iostream>

#include "ResolvedState.h"
#include "Incident.h"
#include "ResponseCoordinator.h"
#include "IncidentEvent.h"
#include "ResolvedState.h"

//---------------------------------------------------------

void ResolvedState::escalate(Incident* inc) {
	
    if(!inc) {
        std::cout << "Invalid Incident" << "\n";
        return;
    }
    
    std::cout << "Incident: " << inc->getID() << " has already been resolved." << std::endl;
}

//---------------------------------------------------------

void ResolvedState::resolve(Incident* inc) {
	
    if(!inc) {
        std::cout << "Invalid Incident" << "\n";
        return;
    }
    
    std::cout << "Incident: " << inc->getID() << " has already been resolved." << std::endl;
}

//---------------------------------------------------------

void ResolvedState::getStatus(Incident* inc) {
	
    if(!inc) {
        std::cout << "Invalid Incident" << "\n";
        return;
    }
    
    std::cout << "===== Status of Incident: =====" << std::endl;
    std::cout << "ID: " << inc->getID() << std::endl;
    std::cout << "Description: " << inc->getDescription() << std::endl;
    std::cout << "State: Resolved"<< std::endl;
    std::cout << "Severity: " << inc->getSeverity() << std::endl;
}

//---------------------------------------------------------
