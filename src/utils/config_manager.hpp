#pragma once
#include <string>
#include <unordered_map>

class ConfigManager {
public:
    static ConfigManager& getInstance();
    void loadConfig(const std::string& filename);
    std::string getValue(const std::string& key) const;

private:
    ConfigManager() = default;
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    std::unordered_map<std::string, std::string> config;
};