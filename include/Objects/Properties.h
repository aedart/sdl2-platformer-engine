#ifndef OBJECTS_PROPERTIES_H
#define OBJECTS_PROPERTIES_H

#include <string>
#include <SDL2/SDL.h>

/**
 * Game Object Properties
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Properties {
    public:
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
         * X position
         */
        float x;

        /**
         * Y Position
         */
        float y;

        /**
         * Flip mode (orientation) of this game object
         */
        SDL_RendererFlip flip;

        /**
         * Constructor
         *
         * @param textureID ID of the texture this game object uses
         * @param width Width of game object
         * @param height Height of game object
         * @param x X position
         * @param y Y position
         * @param flip Flip mode (orientation)
         */
        Properties(
            std::string textureID,
            int width,
            int height,
            float x = 0,
            float y = 0,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        );
};

#endif //OBJECTS_PROPERTIES_H
