#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H
#include "UnitType.h"
#include <string>
#include <iostream>
using namespace std;

class ResponseCoordinator;
class IncidentEvent;
class Incident;

class ResponseUnit {

protected:
	ResponseCoordinator* coordinator;
	string name;
	bool available;

public:
	ResponseUnit(string name, ResponseCoordinator* coordinator);

	virtual UnitType getType() = 0;
	virtual void respond(Incident* inc, IncidentEvent e) = 0;
	void report(Incident* inc, IncidentEvent e);
	bool isAvailable();
	string getName();

	virtual ~ResponseUnit() = default;
};

#endif
