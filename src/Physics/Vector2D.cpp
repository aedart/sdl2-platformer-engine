#include <iostream>
#include <string>

#include "Physics/Vector2D.h"

Vector2D::Vector2D(const float x, const float y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& vector) const
{
    return Vector2D(this->x + vector.x, this->y + vector.y);
}
Vector2D Vector2D::operator-(const Vector2D& vector) const
{
    return Vector2D(this->x - vector.x, this->y - vector.y);
}

Vector2D Vector2D::operator*(const float scalar) const
{
    return Vector2D(this->x * scalar, this->y * scalar);
}

void Vector2D::print(const std::string& message) const
{
    std::cout << message << ": (" << this->x << ", " << this->y << ")" << std::endl;
}
