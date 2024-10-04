#include "config_manager.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

ConfigManager& ConfigManager::getInstance() {
    static ConfigManager instance;
    return instance;
}

void ConfigManager::loadConfig(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open config file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            config[key] = value;
        }
    }
}

std::string ConfigManager::getValue(const std::string& key) const {
    auto it = config.find(key);
    if (it == config.end()) {
        throw std::runtime_error("Config key not found: " + key);
    }
    return it->second;
}