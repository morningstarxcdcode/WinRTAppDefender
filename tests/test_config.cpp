#include "config.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

void createTestConfigFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "key1=value1\n";
    file << "key2=value2\n";
    file.close();
}

void testLoadConfig() {
    const std::string testFile = "test_config.ini";
    createTestConfigFile(testFile);

    auto& config = Config::getInstance();
    config.loadConfig(testFile);

    assert(config.getValue("key1") == "value1");
    assert(config.getValue("key2") == "value2");
    assert(config.getValue("nonexistent") == "");

    std::cout << "Config load and getValue tests passed." << std::endl;
}

int main() {
    testLoadConfig();
    std::cout << "All config tests passed." << std::endl;
    return 0;
}
