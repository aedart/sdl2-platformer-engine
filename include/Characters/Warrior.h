#ifndef CHARACTERS_WARRIOR_H
#define CHARACTERS_WARRIOR_H

#include "Characters/Character.h"
#include "Objects/Properties.h"
#include "Animations/Animation.h"
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
        Animation* animation;

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
         * State, if character is jumping
         */
        bool isJumping;

        /**
         * State, if character is on the ground
         */
        bool isGrounded;

        /**
         * The jump time of this character
         */
        float jumpTime;

        /**
         * The jump force of this character
         */
        float jumpForce;
};

#endif  // CHARACTERS_WARRIOR_H
