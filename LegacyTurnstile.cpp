#include "LegacyTurnstile.h"
#include <iostream>

void LegacyTurnstile::sendSignal(int freq, char flag) {
    std::cout << "[LegacyTurnstile] signal sent (freq=" << freq
              << ", flag=" << flag << ")\n";
}

void LegacyTurnstile::cutPowerFeed() {
    std::cout << "[LegacyTurnstile] power feed cut\n";
}