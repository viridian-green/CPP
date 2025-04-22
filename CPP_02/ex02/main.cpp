#include "fixedPointNumber.hpp"

int main( void )
{
	std::cout << "=== Comparison ===" << std::endl;
    Fixed x(10.5f);
    Fixed y(42.42f);

    std::cout << "x: " << x << ", y: " << y << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    std::cout << "\n=== Arithmetic ===" << std::endl;
    Fixed l(5.5f);
    Fixed m(2);
    std::cout << "l: " << l << ", m: " << m << std::endl;
    std::cout << "l + m: " << (l + m) << std::endl;
    std::cout << "l - m: " << (l - m) << std::endl;
    std::cout << "l * m: " << (l * m) << std::endl;
    std::cout << "l / m: " << (l / m) << std::endl;

    std::cout << "\n=== Functions min & max ===" << std::endl;
    Fixed c(10);
    Fixed d(42.5f);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

    Fixed const e(100);
    Fixed const f(50.1f);
    std::cout << "e (const): " << e << ", f (const): " << f << std::endl;
    std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
    std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl; //check why this is not working
	return 0;
}