#ifndef BUILDING_H
#define BUILDING_H

#include "CampusComponent.h"
#include <vector>

class AccessState;

// Composite: aggregates other CampusComponents and forwards operations
// like lock()/notify() to all of them.
class Building : public CampusComponent {
public:
    explicit Building(const std::string& name);
    ~Building();

    void lock() override;
    void unlock() override;
    void notify(const std::string& msg) override;

    void add(CampusComponent* c) override;
    void remove(CampusComponent* c) override;
    CampusComponent* getChild(int i) override;

    void setAccess(AccessState* s);

private:
    std::vector<CampusComponent*> children;
    AccessState* access;
};

#endif