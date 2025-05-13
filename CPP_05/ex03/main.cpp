#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		//I don't understand how this is implemented...
    	std::cout << "Form created: " << rrf->getName() << ", target: ";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}