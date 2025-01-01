#ifndef CHARACTERS_STALKER_H
#define CHARACTERS_STALKER_H

#include "Animations/SpriteAnimation.h"
#include "Characters/Character.h"
#include "Objects/Properties.h"
#include "Physics/Collider.h"
#include "Physics/RigidBody.h"
#include "Physics/Vector2D.h"

/**
 * Stalker
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Stalker: public Character
{
    public:
        /**
         * Constructor
         *
         * @param properties
         */
        explicit Stalker(const Properties* properties);

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
};

#endif  // CHARACTERS_STALKER_H
