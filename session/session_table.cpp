#include "session_table.hpp"
#include "../util/logger.hpp"

#include <iostream>

using namespace fwos;

void SessionTable::track(
    const Flow& flow) {

    static std::mutex sessionMutex;

    std::lock_guard<std::mutex>
        sessionLock(sessionMutex);

    std::string key =
        flow.srcIp + flow.dstIp;

    sessions[key]++;

    {
        std::lock_guard<std::mutex>
            logLock(globalLogMutex);

        std::cout
            << "[SESSION] active="
            << sessions.size()
            << std::endl;
    }
}