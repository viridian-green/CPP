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
    return (c >= 32 && c <= 126);
}

bool ScalarConverter::isDigit(char c) {
    return c >= '0' && c <= '9';
}

void isChar(std::string literal)
{
    char c = literal[0];
    std::cout << "char : " << c << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void isFloat(std::string literal)
{
    float f = stof(literal);
    std::cout << "char : " << static_cast<char>(f) << std::endl;
    std::cout << "int : " << static_cast<int>(f) << std::endl;
    std::cout << "float  : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void isInt(std::string literal)
{
    int i = stol(literal);
    std::cout << "char : " << static_cast<char>(i) << std::endl;
    std::cout << "int  : " << i << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void isDouble (std::string literal)
{
    double d = stod(literal);
    std::cout << "char : " << static_cast<char>(d) << std::endl;
    std::cout << "int : " << static_cast<int>(d) << std::endl;
   std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}


void ScalarConverter::returnType(std::string literal)
{
    //pseudo literals : literals that don't refer to normal numbers but rather to concepts
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            isFloat(literal);
        else if (literal == "nan" || literal == "+inf" || literal == "-inf")
            isDouble(literal);
        else if (stringLength(literal) == 1 && isPrintable(literal[0]) && !isDigit(literal[0]))
            isChar(literal);
        else {
            char* end = nullptr;
            long intVal = std::strtol(literal.c_str(), &end, 10);
            if (*end == '\0')
                isInt(literal);
            else {
                char* endf = nullptr;
                float floatVal = std::strtof(literal.c_str(), &endf);
                if (*endf == 'f')
                    isFloat(literal);
                else {
                    char* endd = nullptr;
                    double doubleVal = std::strtod(literal.c_str(), &endd);
                    if (*endd == '\0')
                        isDouble(literal);
                    else
                        throw std::invalid_argument("Invalid literal: " + literal);
                }
            }
        }
}

void ScalarConverter::convert(std::string literal)
{
    returnType(literal);
}

