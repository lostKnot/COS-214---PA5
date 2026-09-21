#ifndef LEGACYTURNSTILEADAPTER_H
#define LEGACYTURNSTILEADAPTER_H

class LegacyTurnstileAdapter : AccessGate {

public:
	LegacyTurnstile* device;

	void engage();

	void release();
};

#endif
