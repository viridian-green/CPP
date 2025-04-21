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
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other)const;
	bool operator!=(const Fixed &other) const;
	bool operator+(const Fixed &other) const;
	bool operator-(const Fixed &other) const;
	bool operator*(const Fixed &other) const;
	bool operator/(const Fixed &other) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	static Fixed &min(Fixed &fpn1, Fixed &fpn2);
	static const Fixed &min(const Fixed &fpn1, const Fixed &fpn2);
	static Fixed &max(Fixed &fpn1, Fixed &fpn2);
	static const Fixed &max(const Fixed &fpn1, const Fixed &fpn2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);

#endif