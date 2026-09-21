#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

class ResponseUnit {

protected:
	ResponseCoordinator* coordinator;
	string name;
	bool available;

public:
	virtual UnitType getType() = 0;

	virtual void respond(Incident* inc, IncidentEvent e) = 0;

	void report(Incident* inc, IncidentEvent e);

	bool isAvailable();

	string getName();
};

#endif
