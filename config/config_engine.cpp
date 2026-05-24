#include "config_engine.h"

void ConfigEngine::set(const std::string& k, const std::string& v) {
    data[k] = v;
}

std::string ConfigEngine::get(const std::string& k) {
    return data[k];
}