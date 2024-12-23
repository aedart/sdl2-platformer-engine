#ifndef PHYSICS_VECTOR_2D_H
#define PHYSICS_VECTOR_2D_H

#include <string>

/**
 * Vector 2D
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Vector2D
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
         * @param x X position
         * @param y Y position
         */
        explicit Vector2D(float x = 0, float y = 0);

        /**
         * Addition operator overloading
         *
         * @param vector
         *
         * @return
         */
        Vector2D operator+(const Vector2D& vector) const;

        /**
         * Subtraction operator overloading
         *
         * @param vector
         *
         * @return
         */
        Vector2D operator-(const Vector2D& vector) const;

        /**
         * Multiplication operator overloading
         *
         * @param scalar
         *
         * @return
         */
        Vector2D operator*(float scalar) const;

        /**
         * Outputs vector's coordinates and given message to stdout
         *
         * @param message
         */
        void print(const std::string& message = "") const;
};

#endif // PHYSICS_VECTOR_2D_H
