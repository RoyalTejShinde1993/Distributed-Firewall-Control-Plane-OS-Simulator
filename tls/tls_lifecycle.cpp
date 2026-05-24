#include "tls_lifecycle.h"
#include <iostream>

bool TLSLifecycle::init() {
    std::cout << "[TLS] Initialized" << std::endl;
    return true;
}

bool TLSLifecycle::handshake() {
    std::cout << "[TLS] Handshake OK" << std::endl;
    return true;
}