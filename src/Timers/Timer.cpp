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

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

Timer::Timer() = default;
