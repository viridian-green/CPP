 #include "fixedPointNumber.hpp"

 Fixed::Fixed() : fpn(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int int_num) : fpn(int_num << bitsFractionalPart)
{
	//this should convert const int to the corresponding fixed-point value
	std::cout << "Int constructor called\n";
};

Fixed::Fixed(const float float_num) : fpn (roundf(float_num * (1 << bitsFractionalPart)))
{
	//this should convert const float to the corresponding fixed-point value

	std::cout << "Float constructor called\n";
};

float Fixed::toFloat(void) const {
	return (float(fpn) / float(1 << bitsFractionalPart));
};

int Fixed::toInt(void) const { return (int(fpn) / int(1 << bitsFractionalPart)); }


Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called\n";
	this->fpn = other.fpn;
}

Fixed& Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->fpn = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

std::ostream &operator<<(std::ostream &out, const Fixed &right)
{
    out << right.toFloat(); // Convert the fixed-point value to float for output
    return out;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return fpn;
};

void Fixed::setRawBits( int const raw )
{
	fpn = raw;
};