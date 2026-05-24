#include "control_plane.hpp"

#include "../cluster/cluster_manager.hpp"
#include "../policy/policy_engine.hpp"
#include "../audit/audit_logger.hpp"
#include "../telemetry/metrics.hpp"
#include "../session/session_table.hpp"
#include "../worker/thread_pool.hpp"
#include "../util/logger.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <exception>

using namespace fwos;


void ControlPlane::initialize() {

    std::cout
        << "[FWOS] booting distributed firewall OS"
        << std::endl;
}

void ControlPlane::run() {

    ClusterManager cluster;
    cluster.bootstrap();

    PolicyEngine engine;
    engine.loadDefaultRules();

    AuditLogger audit;
    Metrics metrics;
    SessionTable sessions;

    ThreadPool pool(4);

    for (int i = 0; i < 50; i++) {

        pool.enqueue([i, &engine, &audit, &metrics, &sessions]() {

            try {

                Flow flow;

                flow.srcIp =
                    "10.1.1." + std::to_string(i);

                flow.dstIp =
                    (i % 7 == 0)
                    ? "10.0.0.1"
                    : "8.8.8.8";

                flow.protocol =
                    (i % 2 == 0)
                    ? "tcp"
                    : "udp";

                flow.port =
                    (i % 2 == 0)
                    ? 443
                    : 53;

                bool allowed =
                    engine.evaluate(flow);

                sessions.track(flow);

                metrics.recordPacket(allowed);

                audit.log(flow, allowed);

                {
                    {
                        std::lock_guard<std::mutex>
                             lock(globalLogMutex);

                        std::cout
                              << "[TRACE] "
                              << flow.srcIp
                              << " -> "
                              << flow.dstIp
                              << " proto="
                              << flow.protocol
                              << " port="
                              << flow.port
                              << " verdict="
                              << (allowed
                                  ? "ALLOW"
                                  : "DENY")
                             << std::endl;
                    }
                }

                std::this_thread::sleep_for(
                    std::chrono::milliseconds(40));

            } catch (const std::exception& ex) {

                std::lock_guard<std::mutex>
                    lock(globalLogMutex);

                std::cerr
                    << "[ERROR] worker exception: "
                    << ex.what()
                    << std::endl;

            } catch (...) {

                std::lock_guard<std::mutex>
                    lock(globalLogMutex);

                std::cerr
                    << "[ERROR] unknown worker exception"
                    << std::endl;
            }
        });
    }

    std::this_thread::sleep_for(
        std::chrono::seconds(5));

    metrics.printSummary();

    std::cout
        << "[FWOS] shutdown complete"
        << std::endl;
}