#include "FacilitiesStaff.h"

UnitType FacilitiesStaff::getType() {
	return UnitType::FACILITIES;
}

void FacilitiesStaff::respond(Incident* inc, IncidentEvent e)
{
	if (inc == nullptr)
		return;
	if (e == IncidentEvent::UNIT_ARRIVED || e == IncidentEvent::ESCALATED)
	{
		isolateHazard(inc);
	}
}

void FacilitiesStaff::isolateHazard(Incident* inc) {
	cout << name << " is isolating the hazard." << endl;
	available = false;
}
