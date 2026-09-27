#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include <iostream>
#include <vector>
class Command;

class OperatorConsole {

private:
	std::vector<Command*> history;

public:
	void issue(Command* cmd);
	void undoLast();
};

#endif
