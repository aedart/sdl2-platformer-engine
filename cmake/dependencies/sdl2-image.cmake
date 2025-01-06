# --------------------------------------------------------------------------------------------------
# SDL Image
# @see https://github.com/libsdl-org/SDL_image
#
# @see https://cmake.org/cmake/help/latest/module/FindSDL_image.html
# @see https://www.youtube.com/watch?v=dDnfXOz8kY4
# --------------------------------------------------------------------------------------------------

message("SDL2 Image")

find_package(SDL2_image REQUIRED)

# Debug
message(STATUS "SDL2 Image found: ${SDL2_image_FOUND}")
# print(SDL2_IMAGE_INCLUDE_DIRS SDL2_IMAGE_LIBRARIES)

#include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

#target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(${PROJECT_NAME} SDL2_image::SDL2_image)