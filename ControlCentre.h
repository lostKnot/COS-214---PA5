#ifndef CONTROLCENTRE_H
#define CONTROLCENTRE_H

#include  "ResponseCoordinator.h"
#include <vector>
#include <iostream>
using namespace std;

class ControlCentre : ResponseCoordinator {

public:
	vector<ResponseUnit*> units;

	void registerUnit(ResponseUnit* u) override;

	bool dispatch(Incident* inc, UnitType t) override;

	void notify(ResponseUnit* u, IncidentEvent e, Incident* inc) override;

	void incidentChanged(Incident* inc, IncidentEvent e) override;
};

#endif
