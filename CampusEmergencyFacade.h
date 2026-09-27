#ifndef CAMPUSEMERGENCYFACADE_H
#define CAMPUSEMERGENCYFACADE_H

#include "CampusComponent.h"
#include "OperatorConsole.h"
#include "ResponseCoordinator.h"
#include "LockdownCommand.h"
#include "DispatchCommand.h"
#include "UnlockCommand.h"

class CampusEmergencyFacade {

private:
	CampusComponent* root;
	OperatorConsole* console;
	ResponseCoordinator* coordinator;

public:
	CampusEmergencyFacade(CampusComponent* root, OperatorConsole* console, ResponseCoordinator* coordinator) : root(root), console(console), coordinator(coordinator) {};

	void lockdown(CampusComponent* area, Incident* inc);

	void resolveEmergency(CampusComponent* area, Incident* inc);
};

#endif
