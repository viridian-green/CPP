#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
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