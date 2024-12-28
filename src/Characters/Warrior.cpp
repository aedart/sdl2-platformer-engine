#include <SDL2/SDL.h>

#include "Characters/Character.h"
#include "Graphics/TextureManager.h"
#include "Objects/Properties.h"
#include "Inputs/InputHandler.h"
#include "Animations/Animation.h"
#include "Characters/Warrior.h"

Warrior::Warrior(const Properties* properties) : Character(properties)
{
    this->name = "Warrior";

    this->rigidBody = new RigidBody();

    // TODO: Idle animation
    this->animation = new Animation();
    this->animation->setProperties(
        this->textureID,
        0,
        4,
        120,
        this->flip
    );
}

void Warrior::update(const float delta)
{
    // TODO: handle delta

    const InputHandler& input = InputHandler::getInstance();

    // Idle
    this->rigidBody->unsetForce();
    this->animation->setProperties(
        "warrior_idle",
        0,
        4,
        120,
        this->flip
    );

    // TODO: Uhm... yea... this should be elsewhere defined.
    const int moveSpeed = 5;

    // Move left
    if (input.isKeyDown(SDL_SCANCODE_A)) {
        this->rigidBody->applyForceBackward(moveSpeed);

        this->flip = SDL_FLIP_HORIZONTAL;

        this->animation->setProperties(
            "warrior_run",
            0,
            6,
            120,
            this->flip
        );
    }

    // Move right
    if (input.isKeyDown(SDL_SCANCODE_D)) {
        this->rigidBody->applyForceForward(moveSpeed);

        this->flip = SDL_FLIP_NONE;

        this->animation->setProperties(
            "warrior_run",
            0,
            6,
            120,
            this->flip
        );
    }

    // Compute acceleration, velocity and position
    this->rigidBody->update(delta);

    // Update characters position
    // this->transform->translate(this->rigidBody->getPosition()); // x and y-axis
    this->transform->translateX(this->rigidBody->getPosition().x); // x-axis only
    // this->transform->translateY(this->rigidBody->getPosition().y); // y-axis only, e.g. gravity

    this->animation->update();
}

void Warrior::draw()
{
    // TODO: Need to handle multiple types of animation...
    this->animation->draw(
        this->transform->x,
        this->transform->y,
        this->width,
        this->height
    );
}

void Warrior::clean()
{
    // TODO: Uhm... this seems really heavy!
    TextureManager::getInstance().clean();
}
