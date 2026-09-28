#ifndef INCIDENTSTATE_H
#define INCIDENTSTATE_H

#include "Incident.h"
class Incident;

class IncidentState {

public:
    virtual ~IncidentState() {}
	virtual void escalate(Incident* inc) = 0;
    virtual void resolve(Incident* inc) = 0;
    virtual void getStatus(Incident* inc) = 0;
};

#endif
