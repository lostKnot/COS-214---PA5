#ifndef LOCKEDACCESSSTATE_H
#define LOCKEDACCESSSTATE_H
#include <string>
#include "AccessState.h"

class CampusComponent;

class LockedAccessState : public AccessState {

public:
	void lock(CampusComponent* c);
	void unlock(CampusComponent* c);
	std::string getStatus();
};

#endif
