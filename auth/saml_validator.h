#pragma once
#include <string>

class SAMLValidator {
public:
    bool validate(const std::string& xml);
};