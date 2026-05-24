
#pragma once
#include <vector>
#include <string>

namespace fwos {

struct Flow {
    std::string srcIp;
    std::string dstIp;
    std::string protocol;
    int port;
};

struct Rule {
    std::string action;
    std::string dstIp;
    std::string protocol;
    int port;
};

class PolicyEngine {
private:
    std::vector<Rule> rules;

public:
    void loadDefaultRules();
    bool evaluate(const Flow& flow);
};

}
