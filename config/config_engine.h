#pragma once
#include <unordered_map>
#include <string>

class ConfigEngine {
public:
    void set(const std::string& k, const std::string& v);
    std::string get(const std::string& k);

private:
    std::unordered_map<std::string,std::string> data;
};