#include "Base.hpp"

Base::~Base()
{}

Base *Base::generate(void)
{
    int random = std::rand() % 3;
    if (random == 1)
        return new A();
    else if (random == 2)
        return new B();
     else
        return new C();
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

//If you wanna use dynamic casts with references -- you need to use try-catch blocks
//because should always refer to an object and cannot refer to a null pointer
void Base::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (std::bad_cast&) {}
	std::cout << "Unknown\n";
}
