#include "Bureaucrat.hpp"

int main()
{
	//once an exception, the rest of the code does not execute 
	try
	{
	Bureaucrat Adele("Adele", -3);
	std::cout << Adele;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	Bureaucrat Lila("Lila", 2);
	Lila.incrementGrade();
	Lila.decrementGrade();
	Lila.incrementGrade();
	Lila.incrementGrade();
	std::cout << Lila.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	Bureaucrat Lila("Lila", 1);
	std::cout << Lila.getGrade() << std::endl;
	std::cout << Lila;
	//std::cout << Adele;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}