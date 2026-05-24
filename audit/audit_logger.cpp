
#include "audit_logger.hpp"
#include <iostream>

using namespace fwos;

void AuditLogger::log(const Flow& flow, bool allowed) {

    std::cout
        << "[AUDIT] "
        << flow.srcIp
        << " -> "
        << flow.dstIp
        << " "
        << (allowed ? "ALLOW":"DENY")
        << "\n";
}
