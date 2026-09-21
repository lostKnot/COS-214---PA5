#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

class OperatorConsole {

private:
	vector<Command*> history;

public:
	void issue(Command* cmd);

	void undoLast();
};

#endif
