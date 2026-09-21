#ifndef DISPATCHCOMMAND_H
#define DISPATCHCOMMAND_H

class DispatchCommand : Command {

private:
	ResponseCoordinator* coordinator;
	Incident* incident;
	UnitType unit;

public:
	void execute();

	void undo();
};

#endif
