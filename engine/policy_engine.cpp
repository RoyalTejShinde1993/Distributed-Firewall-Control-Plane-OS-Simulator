#include "policy_engine.h"

bool PolicyEngine::evaluate(const std::string& src_ip,
                             const std::string& dst_ip) {
    // SIMPLE FIREWALL RULE
    if (dst_ip == "10.0.0.1")
        return false;

    return true;
}