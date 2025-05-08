#include "config.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void Config::loadConfig(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << filepath << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            configMap_[key] = value;
        }
    }
}

std::string Config::getValue(const std::string& key) const {
    auto it = configMap_.find(key);
    if (it != configMap_.end()) {
        return it->second;
    }
    return "";
}
