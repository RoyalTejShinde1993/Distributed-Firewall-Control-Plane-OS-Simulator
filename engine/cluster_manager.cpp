#include "cluster_manager.h"
#include <iostream>

void ClusterManager::addNode(const std::string& id) {
    nodes.push_back(id);
}

std::string ClusterManager::electLeader() {
    if (nodes.empty()) return "";

    leader = nodes[0];  // deterministic (simple RAFT-lite)
    std::cout << "[CLUSTER] Leader elected: " << leader << std::endl;
    return leader;
}

std::string ClusterManager::getLeader() {
    return leader;
}