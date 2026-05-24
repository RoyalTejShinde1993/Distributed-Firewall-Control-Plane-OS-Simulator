
#pragma once
#include <string>
#include <unordered_map>

class DistributedPolicy {
public:
    void setPolicy(const std::string& key, const std::string& value);
    std::string getPolicy(const std::string& key);

private:
    std::unordered_map<std::string, std::string> cache;
};