#include "Characters/Warrior.h"

#include <SDL2/SDL.h>

#include "Animations/SpriteAnimation.h"
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

    this->isRunning = false;
    this->isJumping = false;
    this->isFalling = false;
    this->isGrounded = false;
    this->isAttacking = false;

    this->flip = SDL_FLIP_NONE;
    this->jumpTime = Warrior::DEFAULT_JUMP_TIME;
    this->jumpForce = Warrior::DEFAULT_JUMP_FORCE;
    this->attackTime = Warrior::DEFAULT_ATTACK_TIME;
    this->runForce = Warrior::DEFAULT_RUN_FORCE;

    this->collider = new Collider();
    this->collider->setBuffer(-6, -12, 34, 14); // TODO: default/initial buffer for SDL_FLIP_NONE

    this->rigidBody = new RigidBody();
    this->rigidBody->setGravity(3.0f);

    this->animation = new SpriteAnimation();
}

void Warrior::update(const float delta)
{
    // TODO: handle delta

    const InputHandler& input = InputHandler::getInstance();
    const CollisionHandler& collisionHandler = CollisionHandler::getInstance();

    this->isRunning = false;

    // Unset any previous applied force
    this->rigidBody->unsetForce();

    // Move left
    if (input.isKeyDown(SDL_SCANCODE_A) && !this->isAttacking) {
        this->rigidBody->applyForceBackward(this->runForce);
        this->flip = SDL_FLIP_HORIZONTAL;
        this->isRunning = true;

        // Given the sprite sheet that is used, a collider buffer must be set... (mirrored)
        this->collider->setBuffer(-28, -12, 34, 14);
        // TODO: Since buffer is now mirror, there is a risk that character gets stuck in wall!
    }

    // Move right
    if (input.isKeyDown(SDL_SCANCODE_D) && !this->isAttacking) {
        this->rigidBody->applyForceForward(this->runForce);
        this->flip = SDL_FLIP_NONE;
        this->isRunning = true;

        // Given the sprite sheet that is used, a collider buffer must be set...
        this->collider->setBuffer(-6, -12, 34, 14);
        // TODO: Since buffer is now reset, there is a risk that character gets stuck in wall!
    }

    // Crouch (down)?

    // Attack
    if (input.isKeyDown(SDL_SCANCODE_SPACE)) {
        this->rigidBody->unsetForce();
        this->isAttacking = true;
    }

    // Jump
    constexpr auto jumpKey = SDL_SCANCODE_W;
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

    // Fall
    this->isFalling = this->rigidBody->getVelocity().y > 0 && !this->isGrounded;

    // Attack timer
    if (this->isAttacking && this->attackTime > 0) {
        this->attackTime -= delta;
    } else {
        this->isAttacking = false;
        this->attackTime = Warrior::DEFAULT_ATTACK_TIME;
    }

    // Move on x-axis
    this->rigidBody->update(delta);
    this->lastSafePosition.x = this->transform->x;
    this->transform->x += this->rigidBody->getPosition().x;
    this->collider->setBox(this->transform->x, this->transform->y, this->width, this->height);

    if (collisionHandler.mapCollision(this->collider->getBox())) {
        this->transform->x = this->lastSafePosition.x;
    }

    // Move on y-axis
    this->rigidBody->update(delta);
    this->lastSafePosition.y = this->transform->y;
    this->transform->y += this->rigidBody->getPosition().y;
    this->collider->setBox(this->transform->x, this->transform->y, this->width, this->height);

    if (collisionHandler.mapCollision(this->collider->getBox())) {
        this->transform->y = this->lastSafePosition.y;
        this->isGrounded = true;
    } else {
        this->isGrounded = false;
    }

    // Update character's current position
    this->position->x = this->transform->x + this->width / 2;
    this->position->y = this->transform->y + this->height / 2;

    // Finally, update the animation.
    this->resolveAnimation();
    this->animation->update(delta);
}

void Warrior::draw()
{
    // Draw the current animation
    this->animation->draw(
        this->transform->x,
        this->transform->y,
        this->width,
        this->height,
        1.0,
        1.0,
        this->flip
    );

    // Debug Draw the collider box around the character
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

// -----------------------------------------------------------------------------
// Internals
// -----------------------------------------------------------------------------

void Warrior::resolveAnimation()
{
    // TODO: uhm... yea, this is not that nice, but it gets the job done.

    // idle
    this->animation->setProperties(
        "warrior_idle",
        4,
        120
    );
    this->animation->setRepeat(true);

    // running
    if (this->isRunning) {
        this->animation->setProperties(
            "warrior_run",
            6,
            120
        );
    }

    // crouching?

    // jumping
    if (this->isJumping) {
        // Play first part in sprite sheet
        this->animation->setProperties(
            "warrior_jump",
            2,
            65
        );
        this->animation->setRepeat(false);
    }

    // falling
    if (this->isFalling) {
        // Play second part in sprite sheet
        this->animation->setProperties(
            "warrior_jump",
            2,
            65,
            0,
            2
        );
        this->animation->setRepeat(false);
    }

    // attacking
    if (this->isAttacking) {
        this->animation->setProperties(
            "warrior_attack",
            8,
            150
        );
    }
}
