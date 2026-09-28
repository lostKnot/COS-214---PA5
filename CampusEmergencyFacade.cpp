#include "CampusEmergencyFacade.h"

void CampusEmergencyFacade::lockdown(CampusComponent* area, Incident* inc)
{
	if (area == nullptr || inc == nullptr)
	{
		return;
	}

	console->issue(new LockdownCommand(area));
	console->issue(new DispatchCommand(coordinator, inc, UnitType::SECURITY));
}

void CampusEmergencyFacade::resolveEmergency(CampusComponent* area, Incident* inc)
{
	if (area == nullptr || inc == nullptr)
	{
		return;
	}
	console->issue(new UnlockCommand(area));
	inc->resolve();
}
