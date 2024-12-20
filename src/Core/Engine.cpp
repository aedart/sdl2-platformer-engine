#include <iostream>
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

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Engine::Engine() = default;

Engine::~Engine()
{
    // Ensure that instance is reset to null pointer
    instance = nullptr;

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::init()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::cleanup()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::quit()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::update()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::render()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Engine::event()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
