#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

class IncidentState {


public:
	void escalate(Incident* inc);

	void resolve(Incident* inc);

	void getStatus(Incident* inc);
};

#endif
