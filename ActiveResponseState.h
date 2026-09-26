#ifndef ACTIVERESPONSESTATE_H
#define ACTIVERESPONSESTATE_H
#include "AccessState.h"
#include "Incident.h"

class ActiveResponseState : public IncidentState {

public:
	void escalate(Incident* inc);
	void resolve(Incident* inc);
	void getStatus(Incident* inc);
};

#endif
