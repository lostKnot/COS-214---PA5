#ifndef REPORTEDSTATE_H
#define REPORTEDSTATE_H

class ReportedState : IncidentState {


public:
	void escalate(Incident* inc);

	void resolve(Incident* inc);

	void getStatus(Incident* inc);
};

#endif
