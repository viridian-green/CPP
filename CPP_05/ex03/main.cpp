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
		Bureaucrat Lila("Lila", 2);
		Lila.signForm(*rrf);
		Lila.executeForm(*rrf);
		AForm *plantForm;
		plantForm = someRandomIntern.makeForm("shrubberycreation", "Bush");
		Lila.signForm(*plantForm);
		Lila.executeForm(*plantForm);
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Intern newIntern;
		Bureaucrat Lila("Lila", 2);
		AForm *pardonForm;
		pardonForm = newIntern.makeForm("presidential pardon", "Macron");
		Lila.signForm(*pardonForm);
		Lila.executeForm(*pardonForm);
		delete pardonForm;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}