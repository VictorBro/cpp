#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const
{
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long long tmp = (static_cast<long long>(_fixedPointValue) * other._fixedPointValue);
    result.setRawBits(static_cast<int>(tmp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other._fixedPointValue == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    long long tmp = (static_cast<long long>(_fixedPointValue) << _fractionalBits) / other._fixedPointValue;
    result.setRawBits(static_cast<int>(tmp));
    return result;
}

Fixed &Fixed::operator++()
{
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
