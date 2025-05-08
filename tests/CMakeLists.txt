cmake_minimum_required(VERSION 3.8)
project(WinRTAppDefenderTests)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(test_threat_detection tests/test_threat_detection.cpp include/src/threat_detection.cpp)
add_executable(test_config tests/test_config.cpp include/src/config.cpp)

# Link libraries if needed
