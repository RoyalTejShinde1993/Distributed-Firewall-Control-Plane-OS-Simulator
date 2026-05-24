#pragma once
#include <string>

class WAL {
public:
    void append(const std::string& entry);
};