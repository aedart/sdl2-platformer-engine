#ifndef CHARACTERS_WARRIOR_H
#define CHARACTERS_WARRIOR_H

#include "Characters/Character.h"
#include "Objects/Properties.h"
#include "Animations/Animation.h"
#include "Physics/RigidBody.h"

/**
 * Warrior
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Warrior : public Character
{
    public:
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
};

#endif  // CHARACTERS_WARRIOR_H
