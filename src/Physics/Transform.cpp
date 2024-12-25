#include <iostream>
#include <string>

#include "Physics/Transform.h"

Transform::Transform(const float x, const float y) : x(x), y(y) {}

void Transform::translateX(const float x)
{
    this->x += x;
}

void Transform::translateY(const float y)
{
    this->y += y;
}

void Transform::translate(const float x, const float y)
{
    this->x += x;
    this->y += y;
}

void Transform::translate(const Vector2D& vector)
{
    this->x += vector.x;
    this->y += vector.y;
}

void Transform::print(const std::string& message) const
{
    std::cout << message << ": (" << this->x << ", " << this->y << ")" << std::endl;
}