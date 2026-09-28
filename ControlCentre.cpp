#include "ControlCentre.h"
using namespace std;

void ControlCentre::registerUnit(ResponseUnit* u) {
	if (u == nullptr) {
		return;
	}
	for (ResponseUnit* element: units) {
		if (element->getName() == u->getName() && element->getType() == u->getType()) {
			return;
		}
	}
	units.push_back(u);
	cout << u->getName() << " was registered to the control centre." << endl;
}

bool ControlCentre::dispatch(Incident* inc, UnitType t) {
	if (inc == nullptr) {
		return false;
	}
	for (ResponseUnit* unit: units) {
		if (unit->getType() == t) {
			if (unit->isAvailable()) {
				unit->respond(inc, IncidentEvent::UNIT_ARRIVED);
				cout << unit->getName() << " was dispatched by the control centre to respond to an Incident."<< endl;
				return true;
			}
		}
	}
	return false;
}

void ControlCentre::notify(ResponseUnit* u, IncidentEvent e, Incident* inc)
{
	if (u == nullptr || inc == nullptr) {
		return;
	}

	incidentChanged(inc, e);
}

void ControlCentre::incidentChanged(Incident* inc, IncidentEvent e)
{
	if (inc == nullptr)
	{
		return;
	}
	switch (e)	//not sure how all of this should work
	{
		case IncidentEvent::ESCALATED:
			cout << "Incident has been escalated." << endl;
			dispatch(inc, UnitType::SECURITY);
			dispatch(inc, UnitType::MEDICAL);
			break;
		case IncidentEvent::RESOLVED:
			cout << "Incident has been resolved." << endl;
			break;
		case IncidentEvent::UNIT_ARRIVED:
			cout << "A response unit has arrived at the incident." << endl;
			break;
		case IncidentEvent::UNIT_UNAVAILABLE:
			cout << "A response unit is unavailable. Looking for a replacement." << endl;
			break;
	}
}
