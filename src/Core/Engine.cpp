#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Core/Engine.h"

Engine& Engine::getInstance()
{
    if (instance == nullptr) {
        instance = new Engine();
    }

    return *instance;
}

void Engine::destroy()
{
    // Caution: delete will ensure that the destructor is invoked!
    delete instance;

    // Debug
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Engine::Engine():
    running(false),
    screenWidth(0),
    screenHeight(0),
    window(nullptr),
    renderer(nullptr)
{
    // N/A
}

Engine::~Engine()
{
    // Quit if the engine is somehow still running
    if (this->isRunning()) {
        this->quit();
    }

    this->window = nullptr;
    this->renderer = nullptr;

    // Ensure that instance is reset to null pointer
    instance = nullptr;

    // Debug
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool Engine::init(const char *title, const int width, const int height)
{
    // Skip, if already initialised
    if (this->running) {
        return true;
    }

    // ---------------------------------------------------------------------- //

    // Define the SDL flags for initialisation, which must be ready
    // before able to start a game loop.
    constexpr int SDL_FLAGS = SDL_INIT_VIDEO | SDL_INIT_TIMER;

    // Define the SDL Image flags for initialisation.
    constexpr int SDL_IMAGE_FLAGS = IMG_INIT_PNG;

    // Abort if SDL failed to initialise.
    if (SDL_Init(SDL_FLAGS) != 0) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL Init failed: %s", SDL_GetError());
        return this->running = false;
    }

    // Abort if SDL Image failed to initialise
    if (IMG_Init(SDL_IMAGE_FLAGS) == 0) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL Image init failed: %s", SDL_GetError());
        return this->running = false;
    }

    // Abort if SDL ttf failed to initialise
    if (TTF_Init() == -1) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL ttf init failed: %s", TTF_GetError());
        return this->running = false;
    }

    // ---------------------------------------------------------------------- //

    // Set the screen width and height
    this->screenWidth = width;
    this->screenHeight = height;

    // Create SDL window
    this->window = this->makeWindow(title, this->screenWidth, this->screenHeight);
    if (this->window == nullptr) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to create window: %s", SDL_GetError());
        return this->running = false;
    }

    // Create the SDL renderer
    this->renderer = this->makeRenderer(this->window);
    if (this->renderer == nullptr) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to create renderer: %s", SDL_GetError());
        return this->running = false;
    }

    return this->running = true;
}

bool Engine::clean()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return false;
}

void Engine::quit()
{
    // Ensure engine stops running.
    this->running = false;

    // Destroy renderer and window.
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    // Finally, quit SDL components.
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Engine::update()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::render()
{
    SDL_SetRenderDrawColor(this->renderer, 55, 55, 88, 255);

    SDL_RenderClear(this->renderer);

    SDL_RenderPresent(this->renderer);
}

void Engine::event()
{
    SDL_Event event;

    // Poll the SDL for any event.
    SDL_PollEvent(&event);

    // Handle the SDL event
    switch (event.type) {
        case SDL_QUIT:
            this->quit();
        break;

        default:
            // N/A
            break;
    }
}

bool Engine::isRunning() const
{
    return this->running;
}

SDL_Renderer* Engine::getRenderer() const
{
    return this->renderer;
}

int Engine::getScreenWidth() const
{
    return this->screenWidth;
}
int Engine::getScreenHeight() const
{
    return this->screenHeight;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

SDL_Window* Engine::makeWindow(const char* title, const int width, const int height)
{
    return SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
}

SDL_Renderer* Engine::makeRenderer(SDL_Window* window)
{
    return SDL_CreateRenderer(
        window,
        -1,

        // The SDL_RENDERER_PRESENTVSYNC is really important here, or SDL might
        // use way too much CPU.
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
}
