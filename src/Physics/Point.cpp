#include "Physics/Point.h"

Point::Point(const float x, const float y):
    x(x),
    y(y)
{}

Point Point::operator+(const Point& point) const
{
    return Point(this->x + point.x, this->y + point.y);
}

Point operator+=(Point& a, const Point& b)
{
    a.x += b.x;
    a.y += b.y;

    return a;
}

Point Point::operator-(const Point& point) const
{
    return Point(this->x - point.x, this->y - point.y);
}

Point operator-=(Point& a, const Point& b)
{
    a.x -= b.x;
    a.y -= b.y;

    return a;
}

Point Point::operator*(const float scalar) const
{
    return Point(this->x * scalar, this->y * scalar);
}

void Point::print(const std::string& message) const
{
    std::cout << message << ": (" << this->x << ", " << this->y << ")" << std::endl;
}
