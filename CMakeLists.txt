cmake_minimum_required(VERSION 3.8)
project(WinRTAppDefender)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(WinRTAppDefender main.cpp src/defender.cpp)
