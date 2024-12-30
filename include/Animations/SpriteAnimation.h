#ifndef ANIMATIONS_SPRITE_ANIMATION_H
#define ANIMATIONS_SPRITE_ANIMATION_H

#include <SDL2/SDL.h>

#include <string>

#include "Animations/Animation.h"

/**
 * Sprite Animation
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class SpriteAnimation : public Animation
{
    public:
        /**
         * Constructor
         *
         * @param repeat If true, animation will continue to repeat
         *               once it has completed.
         */
        explicit SpriteAnimation(bool repeat = true);

        /**
         * Update this animation
         *
         * @param delta
         */
        virtual void update(float delta);

        /**
         * Draw the animation
         *
         * @param x X position in sprite
         * @param y Y position in sprite
         * @param width Sprite width
         * @param height Sprite height
         * @param scaleX Scale factor for texture x-axis when rendered
         * @param scaleY Scale factor for texture y-axis when rendered
         * @param flip Flip mode
         */
        void draw(
            float x,
            float y,
            float width,
            float height,
            float scaleX = 1.0,
            float scaleY = 1.0,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        ) const;

        /**
         * Set this animation's properties
         *
         * @param textureID The id of the texture
         * @param frames Total amount of frames of this animation
         * @param speed The speed of the animation
         * @param row Row in sprite (y-axis)
         * @param column column in spite (x-axis - the start frame)
         */
        void setProperties(
            const std::string& textureID,
            int frames,
            int speed,
            int row = 0,
            int column = 0
        );

        /**
         * Set the sprite row
         *
         * @param row
         */
        void setRow(int row);

        /**
         * Get the sprite row
         *
         * @return
         */
        [[nodiscard]] int getRow() const;

        /**
         * Set the sprite column (the start frame)
         *
         * @param column
         */
        void setColumn(int column);

        /**
         * Get the sprite column (the start frame)
         *
         * @return
         */
        [[nodiscard]] int getColumn() const;

        /**
         * Increment the sprite row
         */
        void incrementRow();

        /**
         * Decrement the sprite row
         */
        void decrementRow();

        /**
         * Increment the sprite column (the start frame)
         */
        void incrementColumn();

        /**
         * Decrement the sprite column (the start frame)
         */
        void decrementColumn();

    protected:
        /**
         * ID of the texture this game object uses
         */
        std::string textureID;

        /**
         * The total amount of frames of this animation
         */
        int frames;

        /**
         * The sprite row
         */
        int row;

        /**
         * The sprite column (the start frame)
         */
        int column;

        /**
         * The animation speed
         */
        int speed;
};

#endif  // ANIMATIONS_SPRITE_ANIMATION_H
