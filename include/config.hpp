#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <unordered_map>

class Config {
public:
    static Config& getInstance() {
        static Config instance;
        return instance;
    }

    void loadConfig(const std::string& filepath);
    std::string getValue(const std::string& key) const;

private:
    Config() = default;
    ~Config() = default;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    std::unordered_map<std::string, std::string> configMap_;
};

#endif // CONFIG_HPP
