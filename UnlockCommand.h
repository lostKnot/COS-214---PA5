#ifndef UNLOCKCOMMAND_H
#define UNLOCKCOMMAND_H

class UnlockCommand : Command {

public:
	CampusComponent* target;

	void execute();

	void undo();
};

#endif
