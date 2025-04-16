#ifndef FDN_H
# define FDN_H

#include <iostream>

class fixedPointNumber
{
	private:
	int value;
	static const int numberFractionalBits = 8;

	public:
	fixedPointNumber();
	fixedPointNumber(const fixedPointNumber& other);
	fixedPointNumber& operator=(const fixedPointNumber& other);
	~fixedPointNumber();
};

#endif