#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

class CampusComponent {

protected:
	string name;

public:
	void lock();

	virtual void unlock() = 0;

	virtual void notify(string msg) = 0;

	void add(CampusComponent* c);

	void remove(CampusComponent* c);

	CampusComponent* getChild(int i);

	string getName();
};

#endif
