#include "SecurityTeam.h"
using namespace std;

UnitType SecurityTeam::getType() {
	return UnitType::SECURITY;
}

void SecurityTeam::respond(Incident* inc, IncidentEvent e)
{
	if (inc == nullptr)
		return;

	if (e == IncidentEvent::UNIT_ARRIVED || e == IncidentEvent::ESCALATED)
	{
		patrol(inc);
	}
}

void SecurityTeam::patrol(Incident* inc) {
	cout << name << " is patrolling the area for the incident." << endl;
	available = false;
}
