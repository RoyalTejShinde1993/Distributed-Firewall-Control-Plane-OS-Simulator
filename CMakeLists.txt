cmake_minimum_required(VERSION 3.10)

project(fwos_x)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(fwos-x
    main.cpp
    core/control_plane.cpp
    cluster/cluster_manager.cpp
    policy/policy_engine.cpp
    session/session_table.cpp
    worker/thread_pool.cpp
    audit/audit_logger.cpp
    telemetry/metrics.cpp
    util/logger.cpp
)

target_link_libraries(fwos-x PRIVATE Threads::Threads)
