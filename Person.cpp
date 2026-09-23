#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, const std::string& cardID)
    : CampusComponent(name), cardID(cardID) {}

void Person::lock() {
    // Intentional no-op: a person can't be "locked".
}

void Person::unlock() {
    // Intentional no-op, same reasoning as lock().
}

void Person::notify(const std::string& msg) {
    std::cout << "[Person] " << name << " (" << cardID << ") notified: " << msg << "\n";
}