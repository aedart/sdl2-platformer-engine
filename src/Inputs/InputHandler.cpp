#include <SDL2/SDL.h>
#include "Core/Engine.h"
#include "Inputs/InputHandler.h"

InputHandler& InputHandler::getInstance()
{
    if (instance == nullptr) {
        instance = new InputHandler();
    }

    return *instance;
}

void InputHandler::destroy()
{
    delete instance;
}

InputHandler::~InputHandler()
{
    instance = nullptr;
}

void InputHandler::listen()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        // TODO:
        // We should dispatch these events further and allow other parts
        // of the engine / game to react to them, instead of hard-coding
        // logic here...

        switch (event.type) {
            case SDL_QUIT:
                Engine::getInstance().quit();
                break;

            case SDL_KEYDOWN:
                this->handleKeyDown();
                break;

            case SDL_KEYUP:
                this->handleKeyUp();
                break;

            default:
                // TODO: Default handling...?
                break;
        }
    }
}

bool InputHandler::isKeyDown(const SDL_Scancode key) const
{
    return this->keyStates[key] == 1;
}

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

InputHandler::InputHandler()
{
    // Ensure that key states are initially set.
    this->keyStates = this->getKeyboardSnapshot();
};

void InputHandler::handleKeyUp()
{
    this->keyStates = this->getKeyboardSnapshot();
}

void InputHandler::handleKeyDown()
{
    this->keyStates = this->getKeyboardSnapshot();
}

const Uint8* InputHandler::getKeyboardSnapshot(int *numKeys) const
{
    return SDL_GetKeyboardState(numKeys);
}
