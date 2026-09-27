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
	void setState(IncidentState* s);
    void setSeverity(int sev);
	virtual void escalate() = 0;
    virtual void resolve() = 0;
    int getID();
    int getSeverity();
    virtual std::string getStatus() = 0;
    std::string getDescription();
    ResponseCoordinator* getCoordinator();
    
};

#endif
