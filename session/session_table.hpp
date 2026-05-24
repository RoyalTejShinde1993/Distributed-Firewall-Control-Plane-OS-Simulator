
#pragma once
#include "../policy/policy_engine.hpp"
#include <unordered_map>

namespace fwos {

class SessionTable {

private:
    std::unordered_map<std::string,int> sessions;

public:
    void track(const Flow& flow);
};

}
