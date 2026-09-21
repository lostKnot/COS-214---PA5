#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

class AccessPoint : CampusComponent {

private:
	AccessState* access;
	AccessGate* gate;

public:
	void lock();

	void unlock();

	void notify(string msg);

	void setAccess(AccessState* s);
};

#endif
