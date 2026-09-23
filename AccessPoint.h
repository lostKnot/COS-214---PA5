#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include "CampusComponent.h"

class AccessState;
class AccessGate;

// Leaf in the Composite tree. Delegates the physical act of locking to
// an AccessGate (the Adapter's target interface) - it doesn't care
// whether that gate is a modern device or a wrapped legacy turnstile.
class AccessPoint : public CampusComponent {
public:
    explicit AccessPoint(const std::string& name);
    ~AccessPoint();

    void lock() override;
    void unlock() override;
    void notify(const std::string& msg) override;

    void setAccess(AccessState* s);
    void setGate(AccessGate* g); // 0..1 gate

private:
    AccessState* access;
    AccessGate* gate;
};

#endif