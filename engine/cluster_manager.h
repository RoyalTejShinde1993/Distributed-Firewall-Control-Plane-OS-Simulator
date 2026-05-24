#pragma once
#include <vector>
#include <string>

class ClusterManager {
public:
    void addNode(const std::string& id);
    std::string electLeader();
    std::string getLeader();

private:
    std::vector<std::string> nodes;
    std::string leader;
};