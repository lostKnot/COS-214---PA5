#ifndef NORMALACCESSSTATE_H
#define NORMALACCESSSTATE_H

class NormalAccessState : AccessState {


public:
	void lock(CampusComponent* c);

	void unlock(CampusComponent* c);

	string getStatus();
};

#endif
