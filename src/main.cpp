#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Core/Engine.h"

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
    // // Define the SDL flags for initialisation, which must be ready
    // // before able to start a game loop.
    // constexpr int SDL_FLAGS = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    //
    // // Define the SDL Image flags for initialisation.
    // constexpr int SDL_IMAGE_FLAGS = IMG_INIT_PNG;

    // The title of the game screen (window)
    const auto TITLE = "C++ 2D Platform Engine, v0.1.0";

    // Screen width in pixels
    constexpr int SCREEN_WIDTH = 960;

    // Screen height in pixels
    constexpr int SCREEN_HEIGHT = 640;

    // -------------------------------------------------------------------------
    // Initialisation
    // -------------------------------------------------------------------------

    Engine& engine = Engine::getInstance();

    if (!engine.init(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT)) {
        std::cerr << "Failed to initialize engine!" << std::endl;
        return EXIT_FAILURE;
    }

    // -------------------------------------------------------------------------
    // Game loop
    // -------------------------------------------------------------------------

    while(engine.isRunning())
    {
        // Collect all events, e.g. user inputs, etc.
        engine.event();

        // Perform evt. physics calculations, ...etc
        engine.update();

        // Finally, render
        engine.render();
    }

    engine.clean();

    // -------------------------------------------------------------------------
    // Destroy
    // -------------------------------------------------------------------------

    Engine::destroy();

    return EXIT_SUCCESS;
}