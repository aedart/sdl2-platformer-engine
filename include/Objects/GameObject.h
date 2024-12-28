#ifndef OBJECTS_GAME_OBJECT_H
#define OBJECTS_GAME_OBJECT_H

#include <string>
#include <SDL2/SDL.h>

#include "Objects/ObjectInterface.h"
#include "Objects/Properties.h"
#include "Physics/Transform.h"
#include "Physics/Point.h"

/**
 * Game Object
 *
 * @abstract
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class GameObject: public ObjectInterface
{
    public:
        /**
         * Constructor
         *
         * @param properties
         */
        explicit GameObject(const Properties* properties);

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

        /**
         * Get the current position of this game object
         *
         * @return
         */
        [[nodiscard]] Point& getPosition() const;

    protected:
        /**
         * ID of the texture this game object uses
         */
        std::string textureID;

        /**
         * Width of this game object in pixels
         */
        int width;

        /**
         * Height of this game object in pixels
         */
        int height;

        /**
         * Transform utility for this game object
         */
        Transform* transform;

        /**
         * Flip mode (orientation) of this game object
         */
        SDL_RendererFlip flip;

        /**
         * Current position of this game object
         */
        Point* position;
};

#endif // OBJECTS_GAME_OBJECT_H
