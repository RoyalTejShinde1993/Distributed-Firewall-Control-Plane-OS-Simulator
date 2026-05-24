#pragma once
#include <string>

class SSHServer {
public:
    bool authenticate(const std::string& user,
                      const std::string& pass);
};