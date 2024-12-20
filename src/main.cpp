#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/**
 * C++ 2D Platform Engine, based on SDL
 *
 * Source code is inspired by [Madsycode's](https://www.youtube.com/@Madsycode/featured) video
 * tutorials.
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // Define the SDL flags for initialisation, which must be ready
    // before able to start a game loop.
    constexpr int SDL_FLAGS = SDL_INIT_VIDEO | SDL_INIT_TIMER;

    // Define the SDL Image flags for initialisation.
    constexpr int SDL_IMAGE_FLAGS = IMG_INIT_PNG;

    // -------------------------------------------------------------------------
    // Initialisation
    // -------------------------------------------------------------------------

    // Abort if SDL failed to initialise.
    if (SDL_Init(SDL_FLAGS) != 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // Abort if SDL Image failed to initialise
    if (IMG_Init(SDL_IMAGE_FLAGS) == 0) {
        std::cerr << "SDL Image Init Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // Abort if SDL ttf failed to initialise
    if (TTF_Init() == -1) {
        std::cerr << "TTF Init Error: " << TTF_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // -------------------------------------------------------------------------
    // TODO
    // -------------------------------------------------------------------------

    // -------------------------------------------------------------------------
    // Destroy
    // -------------------------------------------------------------------------

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}