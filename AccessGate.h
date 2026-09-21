#ifndef ACCESSGATE_H
#define ACCESSGATE_H

class AccessGate {


public:
	virtual void engage() = 0;

	virtual void release() = 0;
};

#endif
