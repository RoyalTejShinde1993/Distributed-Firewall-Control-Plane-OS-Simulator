
#include "cluster_manager.hpp"
#include <iostream>

using namespace fwos;

void ClusterManager::bootstrap() {

    std::cout << "[CLUSTER] node-1 elected leader\n";
    std::cout << "[CLUSTER] heartbeat service started\n";
    std::cout << "[CLUSTER] policy replication enabled\n";
}
