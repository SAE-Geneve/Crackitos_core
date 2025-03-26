# GTest Option
option(ENABLE_GTESTS "Enable GTests" OFF)
if (ENABLE_GTESTS)
    list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif (ENABLE_GTESTS)

cmake_minimum_required(VERSION 3.18)
project(CrackitosCore)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ENABLE_GTESTS)
    enable_testing()
    find_package(GTest CONFIG REQUIRED)
endif(ENABLE_GTESTS)

# Include all subdirectories
add_subdirectory(core)
