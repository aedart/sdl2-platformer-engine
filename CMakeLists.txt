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

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# --------------------------------------------------------------------------------------------------
# Compiler setup and utilities
# --------------------------------------------------------------------------------------------------

include("cpp-standard")
include("compiler-options")
include("utilities")

# --------------------------------------------------------------------------------------------------
# Project's source files
# --------------------------------------------------------------------------------------------------

# Find all cpp header files
file(GLOB_RECURSE SOURCE_HEADERS "${PROJECT_SOURCE_DIR}/include/*.h")

# Find all cpp files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Set the executable file
add_executable(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/src/main.cpp")

# Add sources to the target
target_sources(${PROJECT_NAME} PUBLIC
        ${SOURCES}
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/include"
    FILES
        ${SOURCE_HEADERS}
)

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

include("dependencies")