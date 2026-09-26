#ifndef LEGACYTURNSTILE_H
#define LEGACYTURNSTILE_H

// Adaptee: an existing legacy device with an incompatible interface.
// Cannot be modified - treat this as a closed third-party library.
class LegacyTurnstile {
public:
    void sendSignal(int freq, char flag);
    void cutPowerFeed();
};

#endif
