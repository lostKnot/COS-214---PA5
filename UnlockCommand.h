#ifndef UNLOCKCOMMAND_H
#define UNLOCKCOMMAND_H

#include "Command.h"
#include "CampusComponent.h"

class UnlockCommand : public Command {

public:
	CampusComponent* target;
    
    explicit UnlockCommand(CampusComponent* target = 0) : target(target) {}
    virtual ~UnlockCommand() {}
    
	void execute();
	void undo();
};

#endif
