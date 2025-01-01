#ifndef PHYSICS_COLLIDER_H
#define PHYSICS_COLLIDER_H

#include <SDL2/SDL.h>

/**
 * Collider
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Collider
{
    public:
        /**
         * Constructor
         *
         * @param box The collider box
         * @param buffer The collider box buffer
         */
        explicit Collider(
            SDL_Rect box = {0, 0, 0, 0},
            SDL_Rect buffer = {0, 0, 0, 0}
        );

        /**
         * Set the collider box
         *
         * Note: The buffer is automatically subtracted from given
         * box position and dimensions.
         *
         * @param x X position
         * @param y Y position
         * @param w Width
         * @param h Height
         */
        void setBox(int x, int y, int w, int h);

        /**
         * Get the collider box
         *
         * @return
         */
        [[nodiscard]] SDL_Rect getBox() const;

        /**
         * Set the collider buffer
         *
         * Note: The box's positions and dimensions are NOT
         * automatically updated when a new buffer is set!
         *
         * @param x X position
         * @param y Y position
         * @param w Width
         * @param h Height
         */
        void setBuffer(int x, int y, int w, int h);

        /**
         * Get the collider buffer
         *
         * @return
         */
        [[nodiscard]] SDL_Rect getBuffer() const;

        /**
         * Determine if this collider collides with the map
         *
         * @return
         */
        [[nodiscard]] bool collidesWithMap() const;

        /**
         * Draw this collider
         */
        void draw();

    protected:
        /**
         * The collider box
         */
        SDL_Rect box;

        /**
         * A buffer box
         */
        SDL_Rect buffer;
};

#endif  // PHYSICS_COLLIDER_H
