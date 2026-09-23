#ifndef PERSON_H
#define PERSON_H

#include "CampusComponent.h"

// Leaf: a person has no children and nothing physical to lock, but still
// implements the CampusComponent interface so Building can cascade
// lock()/notify() over its children uniformly.
class Person : public CampusComponent {
public:
    Person(const std::string& name, const std::string& cardID);

    void lock() override;
    void unlock() override;
    void notify(const std::string& msg) override;

    std::string getCardID() const { return cardID; }

private:
    std::string cardID;
};

#endif