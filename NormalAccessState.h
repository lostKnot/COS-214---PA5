#ifndef NORMALACCESSSTATE_H
#define NORMALACCESSSTATE_H
#include <string>
#include "AccessState.h"

class NormalAccessState : public AccessState {

public:
	void lock(CampusComponent* c);
	void unlock(CampusComponent* c);
	std::string getStatus();
};

#endif
