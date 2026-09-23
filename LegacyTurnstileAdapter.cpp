#include "LegacyTurnstileAdapter.h"

LegacyTurnstileAdapter::LegacyTurnstileAdapter(LegacyTurnstile* device)
    : device(device) {}

LegacyTurnstileAdapter::~LegacyTurnstileAdapter() {
    delete device;
}

void LegacyTurnstileAdapter::engage() {
    // Translate the generic "engage" call into the legacy signal protocol.
    device->sendSignal(400, 'L'); // 400Hz + 'L' happens to mean "lock" on this hardware
}

void LegacyTurnstileAdapter::release() {
    // The legacy device has no direct "unlock" signal - the only way to
    // free the turnstile is to cut its power feed.
    device->cutPowerFeed();
}