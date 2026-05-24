
#pragma once
#include "../policy/policy_engine.hpp"

namespace fwos {

class AuditLogger {
public:
    void log(const Flow& flow, bool allowed);
};

}
