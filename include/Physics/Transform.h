#ifndef PHYSICS_TRANSFORM_H
#define PHYSICS_TRANSFORM_H

#include <string>
#include "Physics/Vector2D.h"

/**
 * Transform
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Transform
{
    public:
        /**
         * X Position
         */
        float x;

        /**
         * Y Position
         */
        float y;

        /**
         * Constructor
         *
         * @param x X Position
         * @param y Y Position
         */
        explicit Transform(float x = 0, float y = 0);

        /**
         * Outputs transform's coordinates and given message to stdout
         *
         * @param message
         */
        void print(const std::string& message = "") const;

    protected:

        /**
         * Translate x position
         *
         * @param x X position
         */
        void translateX(float x);

        /**
         * Translation y position
         *
         * @param y Y position
         */
        void translateY(float y);

        /**
         * Translate x and y positions
         *
         * @param x X position
         * @param y Y position
         */
        void translate(float x, float y);

        /**
         * Translate x and y position using a vector
         *
         * @param vector
         */
        void translate(const Vector2D& vector);
};

#endif  // PHYSICS_TRANSFORM_H
