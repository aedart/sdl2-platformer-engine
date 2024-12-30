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
         * @param flip Flip mode
         */
        void draw(
            float x,
            float y,
            float width,
            float height,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        ) const;

        /**
         * Set this animation's properties
         *
         * @param textureID The id of the texture
         * @param amountFrames Total amount of frames of this animation
         * @param animationSpeed The speed of the animation
         * @param row Row in sprite (y-axis)
         * @param column column in spite (x-axis - the start frame)
         * @param loop If true, the animation restarts from its initial frame.
         *             If false, the animation stops at its last frame
         */
        void setProperties(
            const std::string& textureID,
            int amountFrames,
            int animationSpeed,
            int row = 0,
            int column = 0,
            bool loop = true
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
         * The sprite column (the start frame)
         */
        int column;

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
         * State that determines if the animation should
         * loop.
         */
        bool loop;

        /**
         * The last frame number
         */
        int lastFrame;
};

#endif  // ANIMATIONS_ANIMATION_H
