#include "Physics/RigidBody.h"
#include "Physics/Vector2D.h"

RigidBody::RigidBody():
    mass(DEFAULT_MASS),
    gravity(DEFAULT_GRAVITY)
{
    // TODO: Default values for friction ???
}

void RigidBody::setMass(const float mass)
{
    this->mass = mass;
}

float RigidBody::getMass() const
{
    return this->mass;
}

void RigidBody::setGravity(const float gravity)
{
    this->gravity = gravity;
}

float RigidBody::getGravity() const
{
    return this->gravity;
}

// -----------------------------------------------------------------------------
// Force
// -----------------------------------------------------------------------------

void RigidBody::applyForce(const Vector2D& force)
{
    this->force = force;
}

void RigidBody::applyForceX(const float force)
{
    this->force.x = force;
}
void RigidBody::applyForceY(const float force)
{
    this->force.y = force;
}

void RigidBody::unsetForce()
{
    this->force = Vector2D(0, 0);
}

// -----------------------------------------------------------------------------
// Friction
// -----------------------------------------------------------------------------

void RigidBody::applyFriction(const Vector2D& friction)
{
    this->friction = friction;
}

void RigidBody::unsetFriction()
{
    this->friction = Vector2D(0, 0);
}

// -----------------------------------------------------------------------------
// Position
// -----------------------------------------------------------------------------

Vector2D RigidBody::getPosition() const
{
    return this->position;
}

// -----------------------------------------------------------------------------
// Velocity
// -----------------------------------------------------------------------------

Vector2D RigidBody::getVelocity() const
{
    return this->velocity;
}

// -----------------------------------------------------------------------------
// Acceleration
// -----------------------------------------------------------------------------

Vector2D RigidBody::getAcceleration() const
{
    return this->acceleration;
}

// -----------------------------------------------------------------------------
// Update
// -----------------------------------------------------------------------------

void RigidBody::update(const float delta)
{
    // Compute the acceleration for x and y-axis
    this->acceleration.x = (this->force.x + this->friction.x) / this->mass;
    this->acceleration.y = (this->gravity + this->force.y) / this->mass;

    // Compute the velocity
    this->velocity = this->acceleration * delta;

    // Finally, compute the position
    this->position = this->velocity * delta;
}
