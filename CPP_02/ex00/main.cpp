#include "fixedPointNumber.hpp"


//Fixed-point numbers are a way of representing decimal numbers
//with decimals and binary math without using floats or doubles
//Our code is the base for a fixed-point number
int main()
{
	Fixed a;
	Fixed b( a );//Calls the copy constructor. This is an explicit call that could also look like -->Fixed b = a;
	Fixed c;

	c = b;//Calls the copy assignment operator
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}