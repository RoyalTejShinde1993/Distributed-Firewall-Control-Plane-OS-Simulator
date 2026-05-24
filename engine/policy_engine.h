#pragma once
#include <string>

class PolicyEngine {
public:
    bool evaluate(const std::string& src_ip,
                  const std::string& dst_ip);
};