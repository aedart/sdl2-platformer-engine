#ifndef CHARACTERS_CHARACTER_H
#define CHARACTERS_CHARACTER_H

#include <string>

#include "Objects/GameObject.h"
#include "Objects/Properties.h"

/**
 * Character
 *
 * @abstract
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Character : public GameObject
{
    public:
        /**
         * Constructor
         *
         * @param properties
         */
        explicit Character(const Properties* properties);

        /**
         * Update this object
         *
         * @param delta
         */
        virtual void update(float delta) = 0;

        /**
         * Draw this object
         */
        virtual void draw() = 0;

        /**
         * Clean this object (remove it)
         */
        virtual void clean() = 0;

    protected:
        /**
         * Name of this character
         */
        std::string name;
};

#endif  // CHARACTERS_CHARACTER_H
