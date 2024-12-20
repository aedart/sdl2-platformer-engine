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

Engine::Engine():
    running(false)
{
    // N/A
}

Engine::~Engine()
{
    // Ensure that instance is reset to null pointer
    instance = nullptr;

    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool Engine::init()
{
    this->running = true;

    return this->running;
}

bool Engine::clean()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return false;
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

bool Engine::isRunning() const
{
    return this->running;
}
