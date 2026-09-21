#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H

class ResolvedState : IncidentState {


public:
	void escalate(Incident* inc);

	void resolve(Incident* inc);

	void getStatus(Incident* inc);
};

#endif
