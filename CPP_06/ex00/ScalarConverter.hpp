#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

#include <iostream>
#include <string>

class ScalarConverter
{
    //the ScalarConverter class doesn't store or manage any data 
    //so instatiating objects of that class would be pointless and misleading
    private:
    ScalarConverter();

    public:
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static void convert(std::string literal);
    static void parseInput(std::string literal);

};


#endif