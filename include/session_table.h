#pragma once
#include <string>
#include <unordered_map>

struct Session {
    std::string src;
    std::string dst;
    bool active;
};

class SessionTable {
public:
    void add(std::string id, Session s);
    bool exists(std::string id);

private:
    std::unordered_map<std::string, Session> table;
};