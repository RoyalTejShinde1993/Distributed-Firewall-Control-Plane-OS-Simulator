
#include "metrics.hpp"
#include <iostream>

using namespace fwos;

void Metrics::recordPacket(bool verdict) {

    if(verdict)
        allowed++;
    else
        denied++;
}

void Metrics::printSummary() {

    std::cout << "\n========== FIREWALL SUMMARY ==========\n";

    std::cout << "allowed packets: " << allowed << "\n";
    std::cout << "denied packets : " << denied << "\n";
}
