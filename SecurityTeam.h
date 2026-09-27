#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "ResponseUnit.h"

class SecurityTeam : ResponseUnit {


public:
	SecurityTeam(string name, ResponseCoordinator* coordinator) : ResponseUnit(name, coordinator) {};

	UnitType getType() override;

	void respond(Incident* inc, IncidentEvent e) override;

	void patrol(Incident* inc);
};

#endif
