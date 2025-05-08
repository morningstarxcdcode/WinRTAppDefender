#ifndef THREAT_DETECTION_HPP
#define THREAT_DETECTION_HPP

#include <string>

class ThreatDetection {
public:
    static ThreatDetection& getInstance();

    // Analyze app behavior data and return true if threat detected
    bool analyzeBehavior(const std::string& appName, const std::string& behaviorData);

private:
    ThreatDetection() = default;
    ~ThreatDetection() = default;
    ThreatDetection(const ThreatDetection&) = delete;
    ThreatDetection& operator=(const ThreatDetection&) = delete;

    // Add heuristic or rule-based data members here
};

#endif
