#ifndef LOCKEDACCESSSTATE_H
#define LOCKEDACCESSSTATE_H

class LockedAccessState : AccessState {


public:
	void lock(CampusComponent* c);

	void unlock(CampusComponent* c);

	string getStatus();
};

#endif
