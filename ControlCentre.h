#ifndef CONTROLCENTRE_H
#define CONTROLCENTRE_H

class ControlCentre : ResponseCoordinator {

public:
	vector<ResponseUnit*> units;

	void registerUnit(ResponseUnit* u);

	bool dispatch(Incident* inc, UnitType t);

	void notify(ResponseUnit* u, IncidentEvent e, Incident* inc);

	void incidentChanged(Incident* inc, IncidentEvent e);
};

#endif
