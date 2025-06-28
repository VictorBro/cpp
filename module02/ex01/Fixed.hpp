#pragma once
#include <iostream>

class Fixed
{
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
