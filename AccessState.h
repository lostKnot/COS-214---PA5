#ifndef ACCESSSTATE_H
#define ACCESSSTATE_H

class AccessState {


public:
	virtual void lock(CampusComponent* c) = 0;

	virtual void unlock(CampusComponent* c) = 0;

	virtual string getStatus() = 0;
};

#endif
