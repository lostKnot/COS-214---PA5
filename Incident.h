#ifndef INCIDENT_H
#define INCIDENT_H

class Incident {

private:
	int id;
	string description;
	int severity;
	CampusComponent* location;
	IncidentState* state;
	ResponseCoordinator* coordinator;

public:
	void setState(IncidentState* s);

	void escalate();

	void resolve();

	string getStatus();
};

#endif
