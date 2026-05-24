#pragma once

class TLSLifecycle {
public:
    bool init();
    bool handshake();
};