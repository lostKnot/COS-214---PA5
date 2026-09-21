#ifndef PERSON_H
#define PERSON_H

class Person : CampusComponent {

public:
	string cardID;

	void lock();

	void unlock();

	void notify(string msg);
};

#endif
