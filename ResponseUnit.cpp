#include "ResponseUnit.h"

void ResponseUnit::report(Incident* inc, IncidentEvent e) {
	// TODO - implement ResponseUnit::report
	throw "Not yet implemented";
}

bool ResponseUnit::isAvailable() {
	return this->available;
}

string ResponseUnit::getName() {
	return this->name;
}
