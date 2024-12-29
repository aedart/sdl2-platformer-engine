#include "Collisions/CollisionHandler.h"

CollisionHandler& CollisionHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new CollisionHandler();
    }

    return *instance;
}

void CollisionHandler::destroy()
{
    delete instance;
}

CollisionHandler::~CollisionHandler()
{
    instance = nullptr;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

CollisionHandler::CollisionHandler() = default;
