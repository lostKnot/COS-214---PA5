#ifndef ACTIVERESPONSESTATE_H
#define ACTIVERESPONSESTATE_H

class ActiveResponseState : IncidentState {


public:
	void escalate(Incident* inc);

	void resolve(Incident* inc);

	void getStatus(Incident* inc);
};

#endif
