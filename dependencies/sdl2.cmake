# --------------------------------------------------------------------------------------------------
# SDL
# @see https://www.libsdl.org/
#
# @see https://cmake.org/cmake/help/latest/module/FindSDL.html
# @see https://www.youtube.com/watch?v=dDnfXOz8kY4
# --------------------------------------------------------------------------------------------------

message("SDL2")

find_package(SDL2 REQUIRED)

# Debug
# print(SDL2_INCLUDE_DIRS SDL2_LIBRARIES)
message(STATUS "Found SDL v${SDL2_VERSION}")

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# NOTE: Alternative setup can perhaps act as inspiration. However, it provided cumbersome and failed due
# to strange Threads dependency not being resolved or setup correctly!
# @see https://github.com/SourceCodeDeleted/CMAKE-SDL2-Skeleton
# @see https://github.com/aminosbh/sdl2-cmake-modules