#ifndef MEDICALRESPONDER_H
#define MEDICALRESPONDER_H

#include "ResponseUnit.h"

class MedicalResponder : public ResponseUnit {


public:
	MedicalResponder(string name, ResponseCoordinator* coordinator) : ResponseUnit(name, coordinator) {};

	UnitType getType() override;

	void respond(Incident* inc, IncidentEvent e) override;

	void treat(Incident* inc);
};

#endif
