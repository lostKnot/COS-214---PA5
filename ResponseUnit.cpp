#include "ResponseUnit.h"

ResponseUnit::ResponseUnit(string name, ResponseCoordinator* coordinator) {
	this->name = name;
	this->coordinator = coordinator;
	this->available = true;
}

void ResponseUnit::report(Incident* inc, IncidentEvent e) {
	coordinator->notify(this, e, inc);
}

bool ResponseUnit::isAvailable() {
	return this->available;
}

string ResponseUnit::getName() {
	return this->name;
}
