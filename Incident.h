#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include "IncidentState.h"
#include "CampusComponent.h"
#include "ResponseCoordinator.h"

class Incident {

private:
	int id;
	std::string description;
	int severity;
	CampusComponent* location;
	IncidentState* state;
	ResponseCoordinator* coordinator;

public:
	Incident(int id, const std::string& description, int severity,
	         CampusComponent* location, IncidentState* initialState,
	         ResponseCoordinator* coordinator);
	virtual ~Incident() { delete state; }

	void setState(IncidentState* s);
    void setSeverity(int sev);
	void escalate();
    void resolve();
    int getID();
    int getSeverity();
    std::string getStatus();
    std::string getDescription();
    ResponseCoordinator* getCoordinator();
    
};

#endif