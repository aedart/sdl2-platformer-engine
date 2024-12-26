#include <SDL2/SDL.h>
#include "Timers/Timer.h"

Timer& Timer::getInstance()
{
    if (instance == nullptr) {
        instance = new Timer();
    }

    return *instance;
}

void Timer::destroy()
{
    delete instance;
}

Timer::~Timer()
{
    instance = nullptr;
}

void Timer::tick()
{
    // Obtain the difference since last tick, and scale it down according
    // to the specified targeted frames per second.
    auto deltaTime = (SDL_GetTicks64() - this->lastTime) * (this->getTargetFPS() / 1000.0f);

    // Limit the delta time accordingly
    if (deltaTime > this->getTargetDeltaTime()) {
        deltaTime = this->getTargetDeltaTime();
    }

    // Set the current delta time and update the last tick time
    this->deltaTime = deltaTime;
    this->lastTime = SDL_GetTicks64();
}

float Timer::getDeltaTime() const
{
    return this->deltaTime;
}

float Timer::getLastTime() const
{
    return this->lastTime;
}

void Timer::setTargetFPS(const int fps)
{
    this->targetFps = fps;
}

int Timer::getTargetFPS() const
{
    return this->targetFps;
}

void Timer::setTargetDeltaTime(const float deltaTime)
{
    this->targetDeltaTime = deltaTime;
}

float Timer::getTargetDeltaTime() const
{
    return this->targetDeltaTime;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

Timer::Timer():
    lastTime(SDL_GetTicks64()),
    targetFps(Timer::DEFAULT_TARGET_FPS),
    targetDeltaTime(Timer::DEFAULT_TARGET_DELTA_TIME)
{
    // Ensure that the initial delta time is set, in case of
    // the first run of a game loop.
    this->tick();
}
