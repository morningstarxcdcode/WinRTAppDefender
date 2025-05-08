cmake_minimum_required(VERSION 3.8)
project(WinRTAppDefender)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES main.cpp include/src/defender.cpp include/src/config.cpp include/src/threat_detection.cpp)

add_executable(WinRTAppDefender ${SOURCE_FILES})

# Add compiler flags for C++/WinRT
if(MSVC)
    target_compile_options(WinRTAppDefender PRIVATE /ZW)
    # Link Windows app library
    target_link_libraries(WinRTAppDefender windowsapp)
else()
    # For non-MSVC platforms, remove /ZW flag and windowsapp library
    message(WARNING "C++/WinRT /ZW flag and windowsapp library are only supported on MSVC compiler")
endif()
