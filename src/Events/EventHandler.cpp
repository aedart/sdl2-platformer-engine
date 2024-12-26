#include "Events/EventHandler.h"

EventHandler& EventHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new EventHandler();
    }

    return *instance;
}

void EventHandler::destroy()
{
    delete instance;
}

EventHandler::~EventHandler()
{
    instance = nullptr;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

EventHandler::EventHandler() = default;
