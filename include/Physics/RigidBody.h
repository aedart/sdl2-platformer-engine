#ifndef PHYSICS_RIGID_BODY_H
#define PHYSICS_RIGID_BODY_H

#include "Physics/Vector2D.h"

/**
 * Rigid Body
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class RigidBody
{
    public:
        /**
         * Default mass of a body
         */
        static constexpr float DEFAULT_MASS = 1.0f;

        /**
         * Default gravity of a body
         */
        static constexpr float DEFAULT_GRAVITY = 9.81f;

        /**
         * Default forward motion
         */
        static constexpr int FORWARD = 1;

        /**
         * Default backward motion
         */
        static constexpr int BACKWARD = -1;

        /**
         * Default upward motion
         */
        static constexpr int UPWARD = -1;

        /**
         * Default downward motion
         */
        static constexpr int DOWNWARD = 1;

        /**
         * Constructor
         */
        RigidBody();

        /**
         * Set the mass
         *
         * @param mass
         */
        void setMass(float mass);

        /**
         * Get the mass
         *
         * @return
         */
        [[nodiscard]] float getMass() const;

        /**
         * Set the gravity
         *
         * @param gravity
         */
        void setGravity(float gravity);

        /**
         * Get the gravity
         *
         * @return
         */
        [[nodiscard]] float getGravity() const;

        // -----------------------------------------------------------------------------
        // Force
        // -----------------------------------------------------------------------------

        /**
         * Apply a force on this body
         *
         * @param force
         */
        void applyForce(const Vector2D& force);

        /**
         * Apply a force on the x-axis
         *
         * @param force
         */
        void applyForceX(float force);

        /**
         * Apply a forward motion force on the x-axis (right)
         *
         * @param force
         */
        void applyForceForward(float force);

        /**
         * Apply a backward motion force on the x-axis (left)
         *
         * @param force
         */
        void applyForceBackward(float force);

        /**
         * Apply a force on the y-axis
         *
         * @param force
         */
        void applyForceY(float force);

        /**
         * Apply a upward motion force on the y-axis (up)
         *
         * @param force
         */
        void applyForceUpward(float force);

        /**
         * Apply a downward motion force on the y-axis (down)
         *
         * @param force
         */
        void applyForceDownward(float force);

        /**
         * Remove force
         */
        void unsetForce();

        // -----------------------------------------------------------------------------
        // Friction
        // -----------------------------------------------------------------------------

        /**
         * Apply friction on body
         *
         * @param friction
         */
        void applyFriction(const Vector2D& friction);

        /**
         * Remove friction
         */
        void unsetFriction();

        // -----------------------------------------------------------------------------
        // Position
        // -----------------------------------------------------------------------------

        /**
         * Get the position of this body
         *
         * @return
         */
        [[nodiscard]] Vector2D getPosition() const;

        // -----------------------------------------------------------------------------
        // Velocity
        // -----------------------------------------------------------------------------

        /**
         * Get the velocity of this body
         *
         * @return
         */
        [[nodiscard]] Vector2D getVelocity() const;

        // -----------------------------------------------------------------------------
        // Acceleration
        // -----------------------------------------------------------------------------

        /**
         * Get the acceleration of this body
         *
         * @return
         */
        [[nodiscard]] Vector2D getAcceleration() const;

        // -----------------------------------------------------------------------------
        // Update
        // -----------------------------------------------------------------------------

        /**
         * Update this body
         *
         * Method computes the body's acceleration, velocity and position.
         *
         * @param delta
         */
        void update(float delta);

    protected:
        /**
         * The mass of this body
         */
        float mass;

        /**
         * The gravity that affects this body
         */
        float gravity;

        /**
         * Force to be applied on the x and y-axis
         */
        Vector2D force;

        /**
         * Friction that affects the body
         */
        Vector2D friction;

        /**
         * The position of the body
         */
        Vector2D position;

        /**
         * The velocity (speed) of the body
         */
        Vector2D velocity;

        /**
         * The acceleration of the body
         */
        Vector2D acceleration;
};

#endif  // PHYSICS_RIGID_BODY_H
