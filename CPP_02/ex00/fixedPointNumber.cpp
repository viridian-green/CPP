 #include "fixedPointNumber.hpp"

 Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called\n";
	this->value = other.value;
}

Fixed& Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return value;
};

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	value = raw;
};