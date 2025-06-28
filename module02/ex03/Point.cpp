#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        const_cast<Fixed &>(_x) = other._x; // _x is const, so we use const_cast
        const_cast<Fixed &>(_y) = other._y; // _y is const
    }
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}