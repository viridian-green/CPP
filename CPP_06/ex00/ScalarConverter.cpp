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

void ScalarConverter::parseInput(std::string literal)
{
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            std::cout << "float" << std::endl;
        else if (literal == "nan" || literal == "+inf" || literal == "-inf")
            std::cout << "double" << std::endl;
        else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
            std::cout << "char" << std::endl;
        else {
            char* end = nullptr;
            long intVal = std::strtol(literal.c_str(), &end, 10);
            if (*end == '\0')
                std::cout << "int" << std::endl;
            else {
                char* endf = nullptr;
                float floatVal = std::strtof(literal.c_str(), &endf);
                if (*(endf - 1) == 'f' && *endf == '\0')
                    std::cout << "float" << std::endl;
                else {
                    char* endd = nullptr;
                    double doubleVal = std::strtod(literal.c_str(), &endd);
                    if (*endd == '\0')
                        std::cout << "double" << std::endl;
                    else
                        std::cout << "invalid literal" << std::endl;
                }
            }
        }
    }

void ScalarConverter::convert(std::string literal)
{
    parseInput(literal);
    //to char ?
    //to int
    std::cout << stoi(literal) << std::endl;
    // //to float
    std::cout << stof(literal) << std::endl;
    // //to double
    std::cout << stod(literal) << std::endl;
}