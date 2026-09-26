#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

#include <string>

// Component (GoF Composite pattern).
// Both individual campus elements (leaves) and groups of elements
// (composites, e.g. buildings) are treated uniformly through this interface.
class CampusComponent {
public:
    explicit CampusComponent(const std::string& name) : name(name) {}
    virtual ~CampusComponent() {}

    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void notify(const std::string& msg) = 0;

    // Composite-only operations. Leaves keep the default no-op implementation
    // rather than throwing, so client code can call add/remove on any
    // CampusComponent* without needing to know if it's a leaf or composite.
    virtual void add(CampusComponent* c) { (void)c; }
    virtual void remove(CampusComponent* c) { (void)c; }
    virtual CampusComponent* getChild(int i) { (void)i; return nullptr; }

    std::string getName() const { return name; }

protected:
    std::string name;
};

#endif
