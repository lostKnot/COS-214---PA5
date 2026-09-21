#ifndef MEDICALRESPONDER_H
#define MEDICALRESPONDER_H

class MedicalResponder : ResponseUnit {


public:
	UnitType getType();

	void respond(Incident* inc, IncidentEvent e);

	void treat(Incident* inc);
};

#endif
