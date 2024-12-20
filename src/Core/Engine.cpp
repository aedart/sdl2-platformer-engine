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
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

Engine::Engine() = default;

Engine::~Engine()
{
    Engine::destroy();
}
