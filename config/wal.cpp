#include "wal.h"
#include <fstream>

void WAL::append(const std::string& entry) {
    std::ofstream f("fwos.wal", std::ios::app);
    f << entry << std::endl;
}