#ifndef ANIMATIONS_ANIMATION_H
#define ANIMATIONS_ANIMATION_H

#include <string>
#include <SDL2/SDL.h>

/**
 * Animation
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Animation
{
    public:
        /**
         * Constructor
         */
        Animation();

        /**
         * Update this animation
         */
        void update();

        /**
         * Draw the animation
         *
         * @param x X position in sprite
         * @param y Y position in sprite
         * @param width Sprite width
         * @param height Sprite height
         */
        void draw(float x, float y, float width, float height) const;

        /**
         * Set this animation's properties
         *
         * @param textureID The id of the texture
         * @param row Row in sprite (x-axis)
         * @param amountFrames Total amount of frames of this animation
         * @param animationSpeed The speed of the animation
         * @param flip Flip mode
         */
        void setProperties(
            const std::string& textureID,
            int row,
            int amountFrames,
            int animationSpeed,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        );

    protected:
        /**
         * ID of the texture this game object uses
         */
        std::string textureID;

        /**
         * The sprite row
         */
        int row;

        /**
         * The current frame to be drawn
         */
        int frame;

        /**
         * The total amount of frames of this animation
         */
        int amountFrames;

        /**
         * The animation speed
         */
        int animationSpeed;

        /**
         * Flip mode (orientation) of this animation
         */
        SDL_RendererFlip flip;
};

#endif  // ANIMATIONS_ANIMATION_H
