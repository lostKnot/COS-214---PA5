#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

class SecurityTeam : ResponseUnit {


public:
	UnitType getType();

	void respond(Incident* inc, IncidentEvent e);

	void patrol(Incident* inc);
};

#endif
