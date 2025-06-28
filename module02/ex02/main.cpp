#include "Fixed.hpp"
#include <iostream>

void testArithmetic()
{
    std::cout << "\n===== ARITHMETIC OPERATORS =====\n";

    Fixed a(10.5f);
    Fixed b(2.25f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    Fixed near_zero(0.001f);
    Fixed zero(0);
    std::cout << "\nEdge cases:" << std::endl;
    std::cout << "0.001 * 100 = " << (near_zero * Fixed(100)) << std::endl;

    try
    {
        std::cout << "10.5 / 0 = ";
        std::cout << (a / zero) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testComparison()
{
    std::cout << "\n===== COMPARISON OPERATORS =====\n";

    Fixed a(42.42f);
    Fixed b(42.42f);
    Fixed c(24.24f);

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "a > c: " << (a > c) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
}

void testIncrementDecrement()
{
    std::cout << "\n===== INCREMENT/DECREMENT OPERATORS =====\n";

    Fixed a(42.42f);

    std::cout << "Initial a: " << a << std::endl;

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a after pre-increment: " << a << std::endl;

    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after post-increment: " << a << std::endl;

    std::cout << "--a: " << --a << std::endl;
    std::cout << "a after pre-decrement: " << a << std::endl;

    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a after post-decrement: " << a << std::endl;
}

void testMinMax()
{
    std::cout << "\n===== MIN/MAX FUNCTIONS =====\n";

    Fixed a(42.42f);
    Fixed b(24.24f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    const Fixed c(42.42f);
    const Fixed d(24.24f);

    std::cout << "const c = " << c << ", const d = " << d << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
}

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    testArithmetic();
    testComparison();
    testIncrementDecrement();
    testMinMax();

    return 0;
}