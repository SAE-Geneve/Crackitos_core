cmake_minimum_required(VERSION 3.18)
project(CrackitosCore)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally enable GTest
option(ENABLE_GTESTS "Enable GTests" OFF)
if (ENABLE_GTESTS)
    list(APPEND VCPKG_MANIFEST_FEATURES "tests")
    enable_testing()
    find_package(GTest CONFIG REQUIRED)
endif ()

# === sixit: header-only interface library ===
add_library(sixit INTERFACE)
target_include_directories(sixit INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/externals/sixit
)

# === crackitos_core static library ===
file(GLOB_RECURSE COMMON_SRC core/common/src/*.cc)
file(GLOB_RECURSE MATH_SRC core/math/src/*.cc)
file(GLOB_RECURSE COMMON_HEADERS core/common/include/*.h)
file(GLOB_RECURSE MATH_HEADERS core/math/include/*.h)

add_library(crackitos_core STATIC
        ${COMMON_SRC} ${COMMON_HEADERS}
        ${MATH_SRC} ${MATH_HEADERS}
)

target_include_directories(crackitos_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core/common/include
        ${CMAKE_CURRENT_SOURCE_DIR}/core/math/include
)

# Link sixit headers to crackitos_core
target_link_libraries(crackitos_core PUBLIC sixit)

# Compiler warnings
if(MSVC)
    target_compile_options(crackitos_core PRIVATE /W3 /WX)
else()
    target_compile_options(crackitos_core PRIVATE -Wall -Wextra -Werror)
endif()

# === GTest setup ===
if (ENABLE_GTESTS)
    file(GLOB_RECURSE TEST_FILES core/test/*.cc)
    add_executable(core_tests ${TEST_FILES})
    target_link_libraries(core_tests PRIVATE crackitos_core GTest::gtest GTest::gtest_main)
    add_test(NAME CoreTests COMMAND core_tests)
endif ()
