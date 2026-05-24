
#include "session_table.hpp"
#include <iostream>

using namespace fwos;

void SessionTable::track(const Flow& flow) {

    std::string key = flow.srcIp + flow.dstIp;

    sessions[key]++;

    std::cout
        << "[SESSION] active="
        << sessions.size()
        << "\n";
}
