#include "Characters/Warrior.h"

#include <SDL2/SDL.h>

#include "Animations/Animation.h"
#include "Characters/Character.h"
#include "Graphics/TextureManager.h"
#include "Core/Engine.h"
#include "Cameras/Camera.h"
#include "Inputs/InputHandler.h"
#include "Objects/Properties.h"
#include "Physics/Collider.h"
#include "Physics/Vector2D.h"
#include "Collisions/CollisionHandler.h"

Warrior::Warrior(const Properties* properties) : Character(properties)
{
    this->name = "Warrior";

    this->jumpTime = Warrior::DEFAULT_JUMP_TIME;
    this->jumpForce = Warrior::DEFAULT_JUMP_FORCE;
    this->isJumping = true;
    this->isGrounded = false;

    this->collider = new Collider();

    this->rigidBody = new RigidBody();
    this->rigidBody->setGravity(3.0f);

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
    const CollisionHandler& collisionHandler = CollisionHandler::getInstance();

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

    // Jump
    constexpr auto jumpKey = SDL_SCANCODE_SPACE;
    if (input.isKeyDown(jumpKey) && this->isGrounded) {
        this->isJumping = true;
        this->isGrounded = false;
        this->rigidBody->applyForceUpward(this->jumpForce);
    }
    if (input.isKeyDown(jumpKey) && this->isJumping && this->jumpTime > 0) {
        this->jumpTime -= delta;
        this->rigidBody->applyForceUpward(this->jumpForce);
    } else {
        this->isJumping = false;
        this->jumpTime = Warrior::DEFAULT_JUMP_TIME;
    }

    // Compute acceleration, velocity and position
    this->rigidBody->update(delta);

    // Move on x-axis
    this->rigidBody->update(delta);
    this->lastSafePosition.x = this->transform->x;
    this->transform->x += this->rigidBody->getPosition().x;
    this->collider->setBox(this->transform->x, this->transform->y, 96, 96); // TODO: Why hard-coded values here...!?

    if (collisionHandler.mapCollision(this->collider->getBox())) {
        this->transform->x = this->lastSafePosition.x;
    }

    // Move on y-axis
    this->rigidBody->update(delta);
    this->lastSafePosition.y = this->transform->y;
    this->transform->y += this->rigidBody->getPosition().y;
    this->collider->setBox(this->transform->x, this->transform->y, 96, 96); // TODO: Why hard-coded values here...!?

    if (collisionHandler.mapCollision(this->collider->getBox())) {
        this->transform->y = this->lastSafePosition.y;
        this->isGrounded = true;
    } else {
        this->isGrounded = false;
    }

    // Set jump animation
    if (this->isJumping || !this->isGrounded) {
        // TODO: Strange animation here... 4 frames total, but last two are "falling"...
        this->animation->setProperties(
            "warrior_jump",
            0,
            2,
            80,
            this->flip
        );
    }

    // Update character's current position
    this->position->x = this->transform->x + this->width / 2;
    this->position->y = this->transform->y + this->height / 2;

    // Finally, update the animation.
    this->animation->update();
}

void Warrior::draw()
{
    // Draw the current animation
    this->animation->draw(
        this->transform->x,
        this->transform->y,
        this->width,
        this->height
    );

    // TODO: Draw a rect around the character and follow...
    Vector2D camaraPosition = Camera::getInstance().getPosition();

    auto box = this->collider->getBox();
    box.x -= camaraPosition.x;
    box.y -= camaraPosition.y;

    SDL_RenderDrawRect(Engine::getInstance().getRenderer(), &box);
}

void Warrior::clean()
{
    // TODO: Beneficial to drop the characters sprites here?
    // TextureManager::getInstance().clean();
}
