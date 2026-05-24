#include "ssh_server.h"

bool SSHServer::authenticate(const std::string& user,
                             const std::string& pass) {
    return user == "admin" && pass == "admin";
}