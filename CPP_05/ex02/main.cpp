#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	//once an exception, the rest of the code does not execute 
	try
	{
	Bureaucrat Lila("Lila", 2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}