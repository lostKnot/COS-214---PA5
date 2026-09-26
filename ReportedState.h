#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H
#include "AccessState.h"
#include "Incident.h"

class ReportedState : public IncidentState {

public:
	void escalate(Incident* inc);
	void resolve(Incident* inc);
	void getStatus(Incident* inc);
};

#endif
