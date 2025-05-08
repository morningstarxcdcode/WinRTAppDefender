#include "threat_detection.hpp"
#include <cassert>
#include <iostream>

void testAnalyzeBehavior() {
    auto& detector = ThreatDetection::getInstance();

    // Test with normal behavior
    bool result1 = detector.analyzeBehavior("TestApp", "normal behavior");
    assert(result1 == false);
    std::cout << "Test 1 passed: normal behavior not detected as threat." << std::endl;

    // Test with suspicious behavior
    bool result2 = detector.analyzeBehavior("MaliciousApp", "this app shows suspicious activity");
    assert(result2 == true);
    std::cout << "Test 2 passed: suspicious behavior detected as threat." << std::endl;

    // Test with malware keyword
    bool result3 = detector.analyzeBehavior("MalwareApp", "contains malware signature");
    assert(result3 == true);
    std::cout << "Test 3 passed: malware behavior detected as threat." << std::endl;
}

int main() {
    testAnalyzeBehavior();
    std::cout << "All threat detection tests passed." << std::endl;
    return 0;
}
