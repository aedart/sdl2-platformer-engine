#include "Characters/Stalker.h"

#include "Animations/SpriteAnimation.h"
#include "Characters/Character.h"
#include "Objects/Properties.h"
#include "Physics/Collider.h"
#include "Physics/RigidBody.h"
#include "Physics/Vector2D.h"
#include "Collisions/CollisionHandler.h"
#include "Core/Engine.h"
#include "Objects/Registrar.h"

static Registrar<Stalker> registrar("stalker");

Stalker::Stalker(const Properties* properties)
    : Character(properties)
{
    this->name = "Stalker";

    this->flip = SDL_FLIP_NONE;


    this->collider = new Collider();
    // this->collider->setBuffer(-6, -12, 34, 14); // TODO: default/initial buffer for SDL_FLIP_NONE

    this->rigidBody = new RigidBody();
    this->rigidBody->setGravity(3.5f);

    this->animation = new SpriteAnimation();

    // idle
    this->animation->setProperties(
        "stalker_idle",
        4,
        150
    );
    this->animation->setRepeat(true);
}

void Stalker::update(float delta)
{
    // Move on x-axis
    this->rigidBody->update(delta);
    this->lastSafePosition.x = this->transform->x;
    this->transform->x += this->rigidBody->getPosition().x;
    this->collider->setBox(this->transform->x, this->transform->y, this->width, this->height);

    if (this->collider->collidesWithMap()) {
        this->transform->x = this->lastSafePosition.x;
    }

    // Move on y-axis
    this->rigidBody->update(delta);
    this->lastSafePosition.y = this->transform->y;
    this->transform->y += this->rigidBody->getPosition().y;
    this->collider->setBox(this->transform->x, this->transform->y, this->width, this->height);

    if (this->collider->collidesWithMap()) {
        this->transform->y = this->lastSafePosition.y;
    } else {
    }

    // Update character's current position
    this->position->x = this->transform->x + this->width / 2;
    this->position->y = this->transform->y + this->height / 2;

    // Finally, update the animation.
    //this->resolveAnimation();
    this->animation->update(delta);
}

void Stalker::draw()
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
    this->collider->draw();
}

void Stalker::clean()
{
    // N/A
}
