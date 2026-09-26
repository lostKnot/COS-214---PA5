#include "Building.h"
#include "AccessState.h"
#include <algorithm>
#include <iostream>

Building::Building(const std::string& name)
    : CampusComponent(name), access(nullptr) {}

Building::~Building() {
    for (auto c : children) delete c;
}

void Building::add(CampusComponent* c) {
    children.push_back(c);
}

void Building::remove(CampusComponent* c) {
    children.erase(std::remove(children.begin(), children.end(), c), children.end());
}

CampusComponent* Building::getChild(int i) {
    if (i < 0 || i >= static_cast<int>(children.size())) return nullptr;
    return children[i];
}

void Building::setAccess(AccessState* s) {
    access = s;
}

void Building::lock() {
    // Composite operation: cascade the lock down to every child, whether
    // that child is a Building, an AccessPoint, or a Person.
    for (auto c : children) c->lock();
    if (access) access->lock(this);
    std::cout << "[Building] " << name << " locked (cascaded to "
              << children.size() << " direct children)\n";
}

void Building::unlock() {
    for (auto c : children) c->unlock();
    if (access) access->unlock(this);
    std::cout << "[Building] " << name << " unlocked (cascaded to "
              << children.size() << " direct children)\n";
}

void Building::notify(const std::string& msg) {
    std::cout << "[Building] " << name << ": " << msg << "\n";
    for (auto c : children) c->notify(msg);
}
