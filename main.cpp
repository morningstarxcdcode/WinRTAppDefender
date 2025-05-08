#include <iostream>
#include "include/defender.hpp"
#include "include/config.hpp"

int main() {
    std::cout << "🛡️  WinRT App Behavior Monitor Started" << std::endl;

    Config::getInstance().loadConfig("config.ini");

#ifdef _WIN32
    initializeWinRT();
#endif

    monitorApps();
    blockThreats();
    return 0;
}
