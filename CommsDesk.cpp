#include "CommsDesk.h"

UnitType CommsDesk::getType() {
	return UnitType::COMMS;
}

void CommsDesk::respond(Incident* inc, IncidentEvent e)
{
	if (inc == nullptr)
		return;
	if (e == IncidentEvent::ESCALATED)
	{
		broadcast("Incident has been escalated.");
	}
	else if (e == IncidentEvent::UNIT_ARRIVED)
	{
		broadcast("A response unit has arrived.");
	}
}

void CommsDesk::broadcast(string msg) {
	cout << name << ": " << msg << endl;
}