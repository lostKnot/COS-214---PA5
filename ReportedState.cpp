#include <iostream>

#include "ReportedState.h"
#include "Incident.h"
#include "ResponseCoordinator.h"
#include "IncidentEvent.h"
#include "ResolvedState.h"

//---------------------------------------------------------

void ReportedState::escalate(Incident* inc) {
	
    if(!inc) {
        std::cout << "Invalid Incident" << "\n";
        return;
    }
    
    inc->setSeverity(inc->getSeverity()+1);
    std::cout << "[ReportedState] Incident: " << inc->getID() << " escalated to severity level: " << inc->getSeverity() << "\n";
    
    ResponseCoordinator* coord = inc->getCoordinator();
    if(coord){
        coord->incidentChanged(inc, ESCALATED);
    }
    else{
        std::cout << "No ResponseCoordinator attached to Incident" << "\n";
    }
}

//---------------------------------------------------------

void ReportedState::resolve(Incident* inc) {
	
    if(!inc) {
        std::cout << "Invalid Incident" << "\n";
        return;
    }
    
    ResponseCoordinator* coord = inc->getCoordinator();
    if(coord){
        coord->incidentChanged(inc, RESOLVED);
    }
    else{
        std::cout << "No ResponseCoordinator attached to Incident" << "\n";
    }
    
    inc->setState(new ResolvedState());
}

//---------------------------------------------------------

void ReportedState::getStatus(Incident* inc) {
	
    if(!inc) {
        std::cout << "Invalid Incident" << "\n";
        return;
    }
    
    std::cout << "===== Status of Incident: =====" << std::endl;
    std::cout << "ID: " << inc->getID() << std::endl;
    std::cout << "Description: " << inc->getDescription() << std::endl;
    std::cout << "State: Reported"<< std::endl;
    std::cout << "Severity: " << inc->getSeverity() << std::endl;
}

//---------------------------------------------------------
