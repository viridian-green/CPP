#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Intern.hpp"

int main()
{
	::srand(::time(0));
	AForm *rrf;
	try
	{
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat Lila("Lila", 2);
		Lila.signForm(*rrf);
		Lila.executeForm(*rrf);
		AForm *plantForm;
		plantForm = someRandomIntern.makeForm("shrubberycreation", "Bush");
		Lila.signForm(*plantForm);
		Lila.executeForm(*plantForm);
	}
	catch (std::exception &e)
	{
		delete rrf;
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