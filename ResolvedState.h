#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H
#include "AccessState.h"
#include "Incident.h"
#include "IncidentState.h"

class ResolvedState : public IncidentState {

public:
	void escalate(Incident* inc);
	void resolve(Incident* inc);
	void getStatus(Incident* inc);
};

#endif
