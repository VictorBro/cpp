#pragma once

#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    enum Type
    {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO,
        INVALID
    };

    static Type detectType(const std::string &literal);
    static void printChar(double value, bool impossible);
    static void printInt(double value, bool impossible);
    static void printFloat(double value, bool isPseudo);
    static void printDouble(double value, bool isPseudo);

public:
    static void convert(const std::string &literal);
};
