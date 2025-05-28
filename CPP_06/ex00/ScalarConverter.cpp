#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

size_t ScalarConverter::stringLength(const std::string& str) 
{
    size_t length = 0;
    for (char c : str) 
    {
        (void)c;
        length++;
    }
    return length;
}

bool ScalarConverter::isPrintable(char c) 
{
    return static_cast<unsigned char>(c) >= 32 && static_cast<unsigned char>(c) <= 126;
}

bool ScalarConverter::isDigit(char c) {
    return c >= '0' && c <= '9';
}

void isNan(std::string literal)
{
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : nan"  << "f" << std::endl;
    std::cout << "double : nan" << std::endl;
}

void isChar(std::string literal)
{
    if (literal.size() != 1 || static_cast<unsigned char>(literal[0]) > 127)
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    char c = literal[0];
    if (c < 32 || c > 126 )
        std::cout << "char : impossible" << std::endl;
    else
        std::cout << "char : " << c << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void isFloat(std::string literal)
{
    float f = stof(literal);
    if (f < 32 || f > 126 || f > INT_MAX || f < INT_MIN)
        std::cout << "char : impossible" << std::endl;
    else
        std::cout << "char : " << static_cast<char>(f) << std::endl;
    std::cout << "int : " << static_cast<int>(f) << std::endl;
    std::cout << "float  : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void isInt(std::string literal)
{
    long l;
    try {
        l = std::stol(literal);
    } catch (...) {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int  : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    if (l > INT_MAX || l < INT_MIN) {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int  : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    int i = stol(literal);
    if (i < 32 || i > 126 || i > INT_MAX || i < INT_MIN)
        std::cout << "char : impossible" << std::endl;
    else
        std::cout << "char : " << static_cast<char>(i) << std::endl;
    std::cout << "int  : " << i << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void isDouble (std::string literal)
{
    double d = stod(literal);
     if (d < 32 || d > 126 || d > INT_MAX || d < INT_MIN)
        std::cout << "char : impossible" << std::endl;
    else
        std::cout << "char : " << static_cast<char>(d) << std::endl;
    std::cout << "int : " << static_cast<int>(d) << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}


void isMaxInf(std::string literal)
{
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : +inf" << "f" << std::endl;
    std::cout << "double : +inf" << std::endl;
}

void isMinInf(std::string literal)
{
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : -inf" << "f" << std::endl;
    std::cout << "double : -inf" << std::endl;
}

void ScalarConverter::returnType(std::string literal)
{
        if (literal.length() != 1 && !std::isdigit(literal[0]) && (literal[0] & 0x80)) 
            throw std::invalid_argument("Non-ASCII or non-printable character");
        if (literal == "nan" || literal == "nanf")
            isNan(literal);
        else if (literal == "+inf" || literal == "+inff")
            isMaxInf(literal);
        else if (literal == "-inf" || literal == "-inff")
            isMinInf(literal);
        
        if (stringLength(literal) == 1 && isPrintable(literal[0]) && !isDigit(literal[0]))
            return isChar(literal);
        size_t i = 0;
        if (literal[i] == '+' || literal[i] == '-')
            i++;
        bool hasDot = false;
        bool hasF = false;
        for (; i < literal.length(); ++i) {
        if (literal[i] == '.' && !hasDot) {
            hasDot = true;
        } else if (literal[i] == 'f' && i == literal.length() - 1) {
            hasF = true;
        } else if (!isDigit(literal[i])) {
            throw std::invalid_argument("Invalid literal: " + literal);
        }
        }
        if (hasDot && hasF)
            return isFloat(literal);
        else if (hasDot)
            return isDouble(literal);
        else if (!hasDot && !hasF)
            return isInt(literal);
        throw std::invalid_argument("Invalid literal: " + literal);
}

void ScalarConverter::convert(std::string literal)
{
    returnType(literal);
}

