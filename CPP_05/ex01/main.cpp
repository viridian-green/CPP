#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Form diversity("Diversity Form", 4, 2);
	bool fstatus = diversity.getFormStatus();
	std::cout << "Form status: " << fstatus << std::endl;	
	std::cout << diversity;
	Bureaucrat Bob("Bob", 5);
	Bob.signForm(diversity);
	diversity.beSigned(Bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
	Form diversity("Diversity Form", 4, 2);
	std::cout << diversity;
	Bureaucrat Jean("Jean", 4);
	Jean.signForm(diversity);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}