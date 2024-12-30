#ifndef CHARACTERS_WARRIOR_H
#define CHARACTERS_WARRIOR_H

#include "Characters/Character.h"
#include "Objects/Properties.h"
#include "Animations/SpriteAnimation.h"
#include "Physics/RigidBody.h"
#include "Physics/Collider.h"
#include "Physics/Vector2D.h"

/**
 * Warrior
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Warrior : public Character
{
    public:
        /**
         * Default jump time
         */
        static constexpr float DEFAULT_JUMP_TIME = 15.0f;

        /**
         * Default jump force
         */
        static constexpr float DEFAULT_JUMP_FORCE = 10.0f;

        /**
         * Default run force
         */
        static constexpr float DEFAULT_RUN_FORCE = 4.0f;

        /**
         * Default attack time
         */
        static constexpr float DEFAULT_ATTACK_TIME = 20.0f;

        /**
         * Constructor
         *
         * @param properties
         */
        explicit Warrior(const Properties* properties);

        /**
         * Update this object
         *
         * @param delta
         */
        virtual void update(float delta);

        /**
         * Draw this object
         */
        virtual void draw();

        /**
         * Clean this object (remove it)
         */
        virtual void clean();

    protected:
        /**
         * The current animation of this character
         */
        SpriteAnimation* animation;

        /**
         * The rigid body of this character
         */
        RigidBody* rigidBody;

        /**
         * The collision box of this character
         */
        Collider* collider;

        /**
         * The last "safe" position of the character,
         * in which there was no collision.
         */
        Vector2D lastSafePosition;

        /**
         * The jump time of this character
         */
        float jumpTime;

        /**
         * The jump force of this character
         */
        float jumpForce;

        /**
         * The attack time of this character
         */
        float attackTime;

        /**
         * Run force
         */
        float runForce;

        /**
         * State, if character is running
         */
        bool isRunning;

        /**
         * State, if character is jumping
         */
        bool isJumping;

        /**
         * State, if character is falling
         */
        bool isFalling;

        /**
         * State, if character is on the ground
         */
        bool isGrounded;

        /**
         * State, if character is attacking
         */
        bool isAttacking;

        /**
         * Sets the animation according to its current state
         */
        void resolveAnimation();
};

#endif  // CHARACTERS_WARRIOR_H
