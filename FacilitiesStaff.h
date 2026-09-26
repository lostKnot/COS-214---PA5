#ifndef FACILITIESSTAFF_H
#define FACILITIESSTAFF_H

class FacilitiesStaff : ResponseUnit {


public:
	UnitType getType();

	void respond(Incident* inc, IncidentEvent e);

	void isolateHazard(Incident* inc);
};

#endif
