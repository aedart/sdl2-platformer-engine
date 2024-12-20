# --------------------------------------------------------------------------------------------------
# Loads all 3rd party dependencies
# --------------------------------------------------------------------------------------------------

# Debug
message("Resolving dependencies for ${PROJECT_NAME}")

# Ensure that git is available
find_package(Git REQUIRED)

# Other dependencies...
include("sdl2")
include("sdl2-image")