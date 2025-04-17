#ifndef FDN_H
# define FDN_H

#include <iostream>
#include <math.h>

class Fixed
{
	private:
	int fpn;
	static const int bitsFractionalPart = 8;

	public:
	Fixed();
	Fixed(const float float_num);
	Fixed(const int int_num);
	Fixed(Fixed const &other);
	Fixed& operator=(Fixed const& other);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);

#endif