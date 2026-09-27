#ifndef LOCKDOWNCOMMAND_H
#define LOCKDOWNCOMMAND_H

#include "Command.h"
#include "CampusComponent.h"

class LockdownCommand : public Command {

public:
	CampusComponent* target;
    
    explicit LockdownCommand(CampusComponent* target = 0) : target(target) {}
    virtual ~LockdownCommand() {}
    
	void execute();
	void undo();
};

#endif
