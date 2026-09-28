#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class ResponseCoordinator;
class CampusComponent;
class IncidentState;

class Incident {

private:
	int id;
	std::string description;
	int severity = 0;
	CampusComponent* location = nullptr;
	IncidentState* state = nullptr;
	ResponseCoordinator* coordinator = nullptr;

public:
    Incident(int id, const std::string& desc, int sev, CampusComponent* loc, IncidentState* st, ResponseCoordinator* coord);
    virtual ~Incident();
	void setState(IncidentState* s);
    void setSeverity(int sev);
	virtual void escalate();
    virtual void resolve();
    int getID();
    int getSeverity();
    virtual std::string getStatus();
    std::string getDescription();
    ResponseCoordinator* getCoordinator();
    
};

#endif
