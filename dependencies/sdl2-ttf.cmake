# --------------------------------------------------------------------------------------------------
# SDL Image
# @see https://github.com/libsdl-org/SDL_ttf
#
# @see https://cmake.org/cmake/help/latest/module/FindSDL_ttf.html
# --------------------------------------------------------------------------------------------------

message("SDL2 ttf")

find_package(SDL2_ttf REQUIRED)

# Debug
message(STATUS "SDL2 ttf found: ${SDL2_ttf_FOUND}")

target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf)