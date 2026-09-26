#ifndef ACCESSGATE_H
#define ACCESSGATE_H

// Target interface (GoF Adapter pattern): what AccessPoint expects
// any physical gate/turnstile mechanism to support.
class AccessGate {
public:
    virtual ~AccessGate() {}
    virtual void engage() = 0;  // physically lock/block the gate
    virtual void release() = 0; // physically unlock/free the gate
};

#endif
