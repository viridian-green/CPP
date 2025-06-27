#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"

int main()
{
	::srand(::time(0));
	try
	{
	Bureaucrat Lila("Lila", 146);
	ShrubberyCreationForm shrubberyForm("target");
	Lila.signForm(shrubberyForm);
	Lila.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		try
	{
	Bureaucrat Lila("Lila", 145);
	ShrubberyCreationForm shrubberyForm("target");
	Lila.signForm(shrubberyForm);
	Lila.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		try
	{
	Bureaucrat Lila("Lila", 2);
	ShrubberyCreationForm shrubberyForm("japanese trees");
	Lila.signForm(shrubberyForm);
	Lila.executeForm(shrubberyForm);
	RobotomyRequestForm robotomyForm("Ai washing machine");
	PresidentialPardonForm pardonForm("Macron");
	Lila.signForm(robotomyForm);
	Lila.executeForm(robotomyForm);
	Lila.executeForm(robotomyForm);
	Lila.signForm(pardonForm);
	Lila.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}