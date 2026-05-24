#include "control_plane.h"
#include "policy_engine.h"
#include "distributed_policy.h"
#include "../engine/cluster_manager.h"
#include "../audit/audit_logger.h"

#include <iostream>
#include <thread>
#include <chrono>

ClusterManager cluster;
DistributedPolicy policy;
AuditLogger audit;

void ControlPlane::init() {
    std::cout << "[FWOS-X] Distributed Control Plane Starting..." << std::endl;

    cluster.addNode("node-1");
    cluster.addNode("node-2");
    cluster.addNode("node-3");

    std::string leader = cluster.electLeader();
    policy.setPolicy("BLOCK_IP", "10.0.0.1");

    std::cout << "[FWOS-X] Leader: " << leader << std::endl;
}

void ControlPlane::run() {
    int i = 0;

    while (true) {
        std::string src = "10.1.1." + std::to_string(i % 255);
        std::string dst = (i % 5 == 0) ? "10.0.0.1" : "8.8.8.8";

        std::string block_ip = policy.getPolicy("BLOCK_IP");

        bool allow = (dst != block_ip);

        audit.log("NODE_FLOW " + src + " -> " + dst +
                  (allow ? " ALLOW" : " DENY"));

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        i++;
    }
}