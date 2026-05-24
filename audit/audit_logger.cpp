#include "audit_logger.hpp"
#include "../util/logger.hpp"

#include <iostream>

using namespace fwos;

void AuditLogger::log(
    const Flow& flow,
    bool allowed) {

    std::lock_guard<std::mutex>
        lock(globalLogMutex);

    std::cout
        << "[AUDIT] "
        << flow.srcIp
        << " -> "
        << flow.dstIp
        << " "
        << (allowed ? "ALLOW" : "DENY")
        << std::endl;
}