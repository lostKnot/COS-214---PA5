#include "AccessPoint.h"
#include "AccessState.h"
#include "AccessGate.h"
#include <iostream>

AccessPoint::AccessPoint(const std::string& name)
    : CampusComponent(name), access(nullptr), gate(nullptr) {}

AccessPoint::~AccessPoint() {}

void AccessPoint::setAccess(AccessState* s) { access = s; }
void AccessPoint::setGate(AccessGate* g) { gate = g; }

void AccessPoint::lock() {
    if (access) access->lock(this);
    if (gate) gate->engage(); // works identically whether gate is real or adapted legacy hardware
    std::cout << "[AccessPoint] " << name << " locked\n";
}

void AccessPoint::unlock() {
    if (access) access->unlock(this);
    if (gate) gate->release();
    std::cout << "[AccessPoint] " << name << " unlocked\n";
}

void AccessPoint::notify(const std::string& msg) {
    std::cout << "[AccessPoint] " << name << ": " << msg << "\n";
}
