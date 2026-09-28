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
Incident::Incident(int id, const std::string& description, int severity,
                    CampusComponent* location, IncidentState* initialState,
                    ResponseCoordinator* coordinator)
    : id(id), description(description), severity(severity),
      location(location), state(initialState), coordinator(coordinator) {}

void Incident::escalate() { if (state) state->escalate(this); }
void Incident::resolve()  { if (state) state->resolve(this); }
std::string Incident::getStatus() { if (state) state->getStatus(this); return ""; }