# --------------------------------------------------------------------------------------------------
# Loads all 3rd party dependencies
# --------------------------------------------------------------------------------------------------

# Debug
message(STATUS "Resolving dependencies for ${PROJECT_NAME}")

set(DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/cmake/dependencies")
list(APPEND CMAKE_MODULE_PATH "${DEPENDENCIES_DIR}")

# Ensure that git is available
find_package(Git REQUIRED)

# External dependencies...
include("sdl2")
include("sdl2-image")
include("sdl2-ttf")
include("tinyXML2")