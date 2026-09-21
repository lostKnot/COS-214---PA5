#ifndef BUILDING_H
#define BUILDING_H

class Building : CampusComponent {

private:
	vector<CampusComponent*> children;
	AccessState* access;

public:
	void lock();

	void unlock();

	void notify(string msg);

	void add(CampusComponent* c);

	void remove(CampusComponent* c);

	CampusComponent* getChild(int i);

	string getName();

	void setAccess(AccessState* s);
};

#endif
