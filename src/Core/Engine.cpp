#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Core/Engine.h"
#include "Graphics/TextureManager.h"
#include "Inputs/InputHandler.h"
#include "Timers/Timer.h"
#include "Maps/Parser.h"
#include "Cameras/Camera.h"

// TODO: Clean this stuff
#include "Characters/Warrior.h"
Warrior* player = nullptr;

#include "Characters/Stalker.h"
Stalker* stalker = nullptr;

Engine& Engine::getInstance()
{
    if (instance == nullptr) {
        instance = new Engine();
    }

    return *instance;
}

void Engine::destroy()
{
    // Destroy all singleton instances
    Timer::destroy();
    InputHandler::destroy();
    TextureManager::destroy();
    Parser::destroy();
    Camera::destroy();

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

    // NOTE: current map is a pointer that will be destroyed
    // by the parser!
    this->currentMap = nullptr;

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
    constexpr auto WINDOW_FLAGS = static_cast<SDL_WindowFlags>(SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    this->window = this->makeWindow(title, this->screenWidth, this->screenHeight, WINDOW_FLAGS);
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

    // TODO: ... Map SHOULD be specifiable in the engine...
    const std::string mapID = "demo_map";
    auto& mapParser = Parser::getInstance();

    if (!mapParser.load(mapID, "resources/maps/demo_map.tmx")) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load map: %s", mapID.c_str());
        return this->running = false;
    }

    this->currentMap = mapParser.get(mapID);

    // TODO: ... Texture file SHOULD be specifiable in the engine...
    const std::string texturesFile = "resources/textures.xml";
    if (!TextureManager::getInstance().parseTexture(texturesFile)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to textures files: %s", texturesFile.c_str());
        return this->running = false;
    }

    player = new Warrior(new Properties(
        "warrior_idle",
        48,
        48,
        100,
        200
    ));
    stalker = new Stalker(new Properties(
        "stalker_idle",
        96,
        96,
        450,
        250
    ));

    // Add game objects
    this->gameObjects.push_back(player);
    this->gameObjects.push_back(stalker);

    // TODO: Camera...
    Camera::getInstance().setTarget(player->getPosition());

    // TODO: -- end cleanup

    return this->running = true;
}

bool Engine::clean()
{
    // Cleanup and remove game objects
    for (const auto &object: this->gameObjects) {
        object->clean();
        delete object;
    }
    this->gameObjects.clear();

    // Clean all textures
    TextureManager::getInstance().clean();

    // Warning: Cleaning the map parser here, can, for some reason cause a
    // segfault. For now, we leave this as is...
    //Parser::getInstance().clean();

    return true;
}

void Engine::quit()
{
    // Ensure engine stops running.
    this->running = false;

    // Regardless of circumstance, ensure to free anything that
    // might still be in memory...
    this->clean();

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
    // Debug
    // std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Obtain the delta time
    const auto deltaTime = Timer::getInstance().getDeltaTime();

    // Update the current game map.
    this->currentMap->update(deltaTime);

    // Update game objects
    for (const auto object : this->gameObjects) {
        object->update(deltaTime);
    }

    // Update the camera's position
    Camera::getInstance().update(deltaTime);
}

void Engine::render()
{
    // Skip render if no longer running
    if (!this->running) {
        return;
    }

    SDL_SetRenderDrawColor(this->renderer, 55, 55, 88, 255);

    // Clean previous rendering
    SDL_RenderClear(this->renderer);

    // TODO:
    TextureManager::getInstance().draw( {
        .id = "bg",
        .x = 0,
        .y = 0,
        .width = 576,
        .height = 324,
        .scaleX = 1.2,
        .scaleY = 1.2,
        .scrollRatio = 0.5
    });

    // TODO: end

    // Render the current map
    this->currentMap->render();

    // Render game objects
    for (const auto object : this->gameObjects) {
        object->draw();
    }

    // Finally, show the rendered elements.
    SDL_RenderPresent(this->renderer);
}

void Engine::event()
{
    InputHandler::getInstance().listen();
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

GameMap* Engine::getCurrentMap() const
{
    return this->currentMap;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

SDL_Window* Engine::makeWindow(
    const char* title,
    const int width,
    const int height,
    const SDL_WindowFlags flags
){
    return SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        flags
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
