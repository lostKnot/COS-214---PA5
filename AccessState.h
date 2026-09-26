#ifndef ACCESSSTATE_H
#define ACCESSSTATE_H

class CampusComponent;

class AccessState {

public:
	virtual void lock(CampusComponent* c) = 0;
	virtual void unlock(CampusComponent* c) = 0;
	virtual std::string getStatus() = 0;
};

#endif
