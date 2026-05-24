#pragma once
#include <string>

class PolicyEngine {
public:
    bool evaluate(const std::string& src, const std::string& dst);
};