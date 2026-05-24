cmake_minimum_required(VERSION 3.10)

project(fwos_x)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(fwos-x
    main.cpp
    core/control_plane.cpp
    engine/policy_engine.cpp
    engine/cluster_manager.cpp
    engine/distributed_policy.cpp
    session/session_table.cpp
    worker/thread_pool.cpp
    audit/audit_logger.cpp
)