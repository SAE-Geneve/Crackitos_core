# crackitos_physics/CMakeLists.txt

# Collect all source and header files for the library
file(GLOB_RECURSE COMMON_SRC common/src/*.cc)
file(GLOB_RECURSE MATH_SRC math/src/*.cc)
file(GLOB_RECURSE PHYSICS_SRC physics/src/*.cc)

file(GLOB_RECURSE COMMON_HEADERS common/include/*.h)
file(GLOB_RECURSE MATH_HEADERS math/include/*.h)
file(GLOB_RECURSE PHYSICS_HEADERS physics/include/*.h)

# Create a static library for physics engine
add_library(crackitos_core STATIC
        ${COMMON_SRC} ${COMMON_HEADERS}
        ${MATH_SRC} ${MATH_HEADERS}
        ${PHYSICS_SRC} ${PHYSICS_HEADERS}
)

# Include directories for the library
target_include_directories(crackitos_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/common/include
        ${CMAKE_CURRENT_SOURCE_DIR}/math/include
        ${CMAKE_CURRENT_SOURCE_DIR}/physics/include
)

# Compiler Warnings
if(MSVC)
    target_compile_options(crackitos_core PRIVATE /W3 /WX)
else()
    target_compile_options(crackitos_core PRIVATE -Wall -Wextra -Werror)
endif()