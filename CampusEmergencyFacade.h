#ifndef CAMPUSEMERGENCYFACADE_H
#define CAMPUSEMERGENCYFACADE_H

class CampusEmergencyFacade {

private:
	CampusComponent* root;
	OperatorConsole* console;
	ResponseCoordinator coordinator;

public:
	void lockdown(CampusComponent* area, Incident* inc);

	void resolveEmergency(CampusComponent* area, Incident* inc);
};

#endif
