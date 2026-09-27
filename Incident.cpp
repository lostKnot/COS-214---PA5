#include "Incident.h"

void Incident::setState(IncidentState* s) {
    
    if (this->state != s) {
            delete this->state;
            this->state = s;
        }
}

//---------------------------------------------------------

void Incident::setSeverity(int sev){
    
    this->severity = sev;
}

//---------------------------------------------------------

int Incident::getID() {
    
    return this->id;
}

//---------------------------------------------------------

int Incident::getSeverity() {
    
    return this->severity;
}

//---------------------------------------------------------

ResponseCoordinator* Incident::getCoordinator(){
    
    return this->coordinator;
}

//---------------------------------------------------------

std::string Incident::getDescription(){
    
    return this->description;
}

//---------------------------------------------------------
