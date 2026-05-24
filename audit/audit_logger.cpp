#include "audit_logger.h"
#include <iostream>

void AuditLogger::log(const std::string& msg) {
    std::cout << "[AUDIT] " << msg << std::endl;
}