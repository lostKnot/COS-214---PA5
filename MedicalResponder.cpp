#include "MedicalResponder.h"

UnitType MedicalResponder::getType() {
	return UnitType::MEDICAL;
}

void MedicalResponder::respond(Incident* inc, IncidentEvent e)
{
	if (inc == nullptr)
		return;
	if (e == IncidentEvent::UNIT_ARRIVED || e == IncidentEvent::ESCALATED)
	{
		treat(inc);
	}
}

void MedicalResponder::treat(Incident* inc) {
	cout << name << " is treating people at the incident." << endl;
	available = false;
}