#ifndef LOCKDOWNCOMMAND_H
#define LOCKDOWNCOMMAND_H

class LockdownCommand : Command {

public:
	CampusComponent* target;

	void execute();

	void undo();
};

#endif
