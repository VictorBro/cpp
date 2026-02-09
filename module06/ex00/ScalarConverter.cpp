#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// --- Type detection ---

static bool isPseudoLiteral(const std::string &s)
{
    return s == "nan" || s == "nanf"
        || s == "+inf" || s == "+inff"
        || s == "-inf" || s == "-inff"
        || s == "inf" || s == "inff";
}

static bool isCharLiteral(const std::string &s)
{
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isIntLiteral(const std::string &s)
{
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

static bool isFloatLiteral(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;
    std::string trimmed = s.substr(0, s.length() - 1);
    if (trimmed.empty())
        return false;
    bool hasDot = false;
    bool hasDigitBefore = false;
    bool hasDigitAfter = false;
    size_t i = 0;
    if (trimmed[i] == '+' || trimmed[i] == '-')
        i++;
    if (i == trimmed.length())
        return false;
    for (; i < trimmed.length(); i++)
    {
        if (trimmed[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(trimmed[i]))
        {
            if (hasDot)
                hasDigitAfter = true;
            else
                hasDigitBefore = true;
        }
        else
            return false;
    }
    return hasDot && hasDigitBefore && hasDigitAfter;
}

static bool isDoubleLiteral(const std::string &s)
{
    if (s.empty())
        return false;
    bool hasDot = false;
    bool hasDigitBefore = false;
    bool hasDigitAfter = false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(s[i]))
        {
            if (hasDot)
                hasDigitAfter = true;
            else
                hasDigitBefore = true;
        }
        else
            return false;
    }
    return hasDot && hasDigitBefore && hasDigitAfter;
}

ScalarConverter::Type ScalarConverter::detectType(const std::string &literal)
{
    if (isPseudoLiteral(literal))
        return PSEUDO;
    if (isCharLiteral(literal))
        return CHAR;
    if (isIntLiteral(literal))
        return INT;
    if (isFloatLiteral(literal))
        return FLOAT;
    if (isDoubleLiteral(literal))
        return DOUBLE;
    return INVALID;
}

void ScalarConverter::printChar(double value, bool impossible)
{
    if (impossible || std::isnan(value) || std::isinf(value)
        || value < 0 || value > 127
        || value != static_cast<long long>(value))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible)
{
    if (impossible || std::isnan(value) || std::isinf(value)
        || value > static_cast<double>(INT_MAX)
        || value < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool isPseudo)
{
    float f = static_cast<float>(value);
    if (isPseudo || std::isnan(value) || std::isinf(value))
    {
        if (std::isnan(value))
            std::cout << "float: nanf" << std::endl;
        else if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else if (std::isinf(f))
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: ";
        // Check if f is a whole number that can be safely cast to long long
        // 1e15 is below double's precision limit (2^53) where integers are exact
        if (f == static_cast<long long>(f)
            && !std::isinf(f)
            && f >= -1e15 && f <= 1e15)
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value, bool isPseudo)
{
    if (isPseudo || std::isnan(value) || std::isinf(value))
    {
        if (std::isnan(value))
            std::cout << "double: nan" << std::endl;
        else if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "double: ";
        // Check if value is a whole number that can be safely cast to long long
        // 1e15 is below double's precision limit (2^53) where integers are exact
        if (value == static_cast<long long>(value)
            && !std::isinf(value)
            && value >= -1e15 && value <= 1e15)
            std::cout << std::fixed << std::setprecision(1) << value << std::endl;
        else
            std::cout << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    Type type = detectType(literal);
    double value = 0;
    bool impossible = false;

    switch (type)
    {
    case CHAR:
        value = static_cast<double>(literal[1]);
        break;
    case INT:
    {
        char *endptr = NULL;
        errno = 0;
        long l = std::strtol(literal.c_str(), &endptr, 10);
        if (errno == ERANGE || *endptr != '\0')
        {
            impossible = true;
            value = static_cast<double>(l);
        }
        else
            value = static_cast<double>(l);
        break;
    }
    case FLOAT:
    {
        char *endptr = NULL;
        errno = 0;
        double d = std::strtod(literal.c_str(), &endptr);
        if (errno == ERANGE || (endptr && *endptr != 'f'))
            impossible = true;
        value = d;
        break;
    }
    case DOUBLE:
    {
        char *endptr = NULL;
        errno = 0;
        value = std::strtod(literal.c_str(), &endptr);
        if (errno == ERANGE || *endptr != '\0')
            impossible = true;
        break;
    }
    case PSEUDO:
    {
        value = std::strtod(literal.c_str(), NULL);
        printChar(value, true);
        printInt(value, true);
        printFloat(value, true);
        printDouble(value, true);
        return;
    }
    case INVALID:
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value, impossible);
    printDouble(value, impossible);
}
