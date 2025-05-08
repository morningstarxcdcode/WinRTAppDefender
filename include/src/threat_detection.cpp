#include "threat_detection.hpp"
#include <iostream>

ThreatDetection& ThreatDetection::getInstance() {
    static ThreatDetection instance;
    return instance;
}

bool ThreatDetection::analyzeBehavior(const std::string& appName, const std::string& behaviorData) {
    // Simple heuristic example: flag app if behaviorData contains suspicious keywords
    if (behaviorData.find("suspicious") != std::string::npos ||
        behaviorData.find("malware") != std::string::npos) {
        std::cout << "Threat detected in app: " << appName << std::endl;
        return true;
    }
    return false;
}
