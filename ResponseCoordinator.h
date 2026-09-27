#ifndef RESPONSECOORDINATOR_H
#define RESPONSECOORDINATOR_H

#include  "ResponseUnit.h"
#include "Incident.h"
#include "UnitType.h"
#include "IncidentEvent.h"

class ResponseCoordinator {


public:
	virtual void registerUnit(ResponseUnit* u) = 0;

	virtual bool dispatch(Incident* inc, UnitType t) = 0;

	virtual void notify(ResponseUnit* u, IncidentEvent e, Incident* inc) = 0;

	virtual void incidentChanged(Incident* inc, IncidentEvent e) = 0;

	virtual ~ResponseCoordinator() = default;
};

#endif
