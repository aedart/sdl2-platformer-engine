#ifndef PHYSICS_POINT_H
#define PHYSICS_POINT_H

#include <iostream>

/**
 * Point
 *
 * @author Alin Eugen Deac <aedart@gmail.com>
 */
class Point
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
         * @param x X position
         * @param y Y position
         */
        explicit Point(float x = 0, float y = 0);

        /**
         * Addition operator overloading
         *
         * @param point
         *
         * @return
         */
        Point operator+(const Point& point) const;

        /**
         * Addition operator overloading
         *
         * @param a Point a
         * @param b Point b
         *
         * @return
         */
        friend Point operator+=(Point& a, const Point& b);

        /**
         * Subtraction operator overloading
         *
         * @param point
         *
         * @return
         */
        Point operator-(const Point& point) const;

        /**
         * Subtraction operator overloading
         *
         * @param a Point a
         * @param b Point b
         *
         * @return
         */
        friend Point operator-=(Point& a, const Point& b);

        /**
         * Multiplication operator overloading
         *
         * @param scalar
         *
         * @return
         */
        Point operator*(float scalar) const;

        /**
         * Outputs point's coordinates and given message to stdout
         *
         * @param message
         */
        void print(const std::string& message = "") const;
};

#endif  // PHYSICS_POINT_H
