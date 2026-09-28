#ifndef FACILITIESSTAFF_H
#define FACILITIESSTAFF_H

#include "ResponseUnit.h"

class FacilitiesStaff : ResponseUnit {


public:
	FacilitiesStaff(string name, ResponseCoordinator* coordinator) : ResponseUnit(name, coordinator) {};

	UnitType getType() override;

	void respond(Incident* inc, IncidentEvent e) override;

	void isolateHazard(Incident* inc);
};

#endif
