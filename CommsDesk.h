#ifndef COMMSDESK_H
#define COMMSDESK_H

#include "ResponseUnit.h"

class CommsDesk : public ResponseUnit {


public:
	CommsDesk(string name, ResponseCoordinator* coordinator) : ResponseUnit(name, coordinator) {};

	UnitType getType() override;

	void respond(Incident* inc, IncidentEvent e) override;

	void broadcast(string msg);
};

#endif
