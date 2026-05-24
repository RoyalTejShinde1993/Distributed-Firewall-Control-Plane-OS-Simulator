#include "policy_engine.h"

bool PolicyEngine::evaluate(const std::string& src, const std::string& dst) {
    if (dst == "10.0.0.1") return false;
    return true;
}