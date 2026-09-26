#ifndef RESPONSECOORDINATOR_H
#define RESPONSECOORDINATOR_H

class ResponseCoordinator {


public:
	virtual void registerUnit(ResponseUnit* u) = 0;

	virtual bool dispatch(Incident* inc, UnitType t) = 0;

	virtual void notify(ResponseUnit* u, IncidentEvent e, Incident* inc) = 0;

	virtual void incidentChanged(Incident* inc, IncidentEvent e) = 0;
};

#endif
