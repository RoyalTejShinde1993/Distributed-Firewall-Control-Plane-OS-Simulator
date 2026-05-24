#include "distributed_policy.h"

void DistributedPolicy::setPolicy(const std::string& key, const std::string& value) {
    cache[key] = value;
}

std::string DistributedPolicy::getPolicy(const std::string& key) {
    return cache[key];
}