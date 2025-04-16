#ifndef FDN_H
# define FDN_H

#include <iostream>

class Fixed
{
	private:
	int value;
	static const int bitsFractionalPart = 8;

	public:
	Fixed();
	Fixed(Fixed const &other);
	Fixed& operator=(Fixed const& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif