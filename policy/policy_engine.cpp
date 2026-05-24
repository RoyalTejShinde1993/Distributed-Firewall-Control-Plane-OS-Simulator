
#include "policy_engine.hpp"
#include <iostream>

using namespace fwos;

void PolicyEngine::loadDefaultRules() {

    rules.push_back({"DENY","10.0.0.1","tcp",443});
    rules.push_back({"DENY","8.8.8.8","udp",53});

    std::cout << "[POLICY] loaded " << rules.size() << " rules\n";
}

bool PolicyEngine::evaluate(const Flow& flow) {

    for(const auto& rule : rules) {

        bool ipMatch = (rule.dstIp == flow.dstIp);
        bool protoMatch = (rule.protocol == flow.protocol);
        bool portMatch = (rule.port == flow.port);

        if(ipMatch && protoMatch && portMatch) {
            return rule.action != "DENY";
        }
    }

    return true;
}
