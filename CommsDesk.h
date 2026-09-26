#ifndef COMMSDESK_H
#define COMMSDESK_H

class CommsDesk : ResponseUnit {


public:
	UnitType getType();

	void respond(Incident* inc, IncidentEvent e);

	void broadcast(string msg);
};

#endif
