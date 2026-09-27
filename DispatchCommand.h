#ifndef DISPATCHCOMMAND_H
#define DISPATCHCOMMAND_H

#include <iostream>

#include "Command.h"
#include "Incident.h"
#include "ResponseCoordinator.h"
#include "UnitType.h"

class DispatchCommand : public Command {

private:
	ResponseCoordinator* coordinator;
	Incident* incident;
	UnitType unit;

public:
    DispatchCommand(ResponseCoordinator* coord, Incident* inc, UnitType u);
    virtual ~DispatchCommand() {}
    
	void execute();
	void undo();
};

#endif
