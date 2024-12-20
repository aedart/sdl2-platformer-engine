# --------------------------------------------------------------------------------------------------
# Top level Project configuration
# --------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.30)

project(sdl2-platformer-engine LANGUAGES CXX)

# --------------------------------------------------------------------------------------------------
# Setup cmake module directories
#
# @see https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html
# --------------------------------------------------------------------------------------------------

set(DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")

list(
    APPEND
    CMAKE_MODULE_PATH

    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    "${DEPENDENCIES_DIR}"
)

# --------------------------------------------------------------------------------------------------
# Compiler setup and utilities
# --------------------------------------------------------------------------------------------------

include("cpp-standard")
include("compiler-options")
include("utilities")

# --------------------------------------------------------------------------------------------------
# Project's source files
# --------------------------------------------------------------------------------------------------

# Header files
include_directories("${PROJECT_SOURCE_DIR}/include")

# Add all c source files under the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# Copy resources (gfx... etc) into the build directory
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/resources"
        "${PROJECT_BINARY_DIR}/resources"
        COMMENT "Copying resources into binary directory"
)
add_dependencies(${PROJECT_NAME} copy_resources)

# --------------------------------------------------------------------------------------------------
# Dependencies
# --------------------------------------------------------------------------------------------------

include("dependencies.cmake")