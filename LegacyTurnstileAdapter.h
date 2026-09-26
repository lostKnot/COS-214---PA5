#ifndef LEGACYTURNSTILEADAPTER_H
#define LEGACYTURNSTILEADAPTER_H

#include "AccessGate.h"
#include "LegacyTurnstile.h"

// Adapter: translates the AccessGate interface the rest of the system
// expects into the specific calls the legacy device actually understands.
class LegacyTurnstileAdapter : public AccessGate {
public:
    explicit LegacyTurnstileAdapter(LegacyTurnstile* device);
    ~LegacyTurnstileAdapter();

    void engage() override;
    void release() override;

private:
    LegacyTurnstile* device;
};

#endif
