#include <iostream>
#include "include/defender.hpp"

int main() {
    std::cout << "🛡️  WinRT App Behavior Monitor Started" << std::endl;
    monitorApps();
    blockThreats();
    return 0;
}
