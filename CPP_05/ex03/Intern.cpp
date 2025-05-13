#include "Intern.hpp"

Intern::Intern()
{}
// Intern::Intern(const Intern &other)
// {}
// Intern& Intern::operator=(const Intern &other)
// {}

Intern::~Intern()
{}

AForm* Intern::ShrubberyCreation(std::string target)
{
	return(new ShrubberyCreationForm(target));
}
AForm* Intern::RobotomyRequest(std::string target)
{
	return(new RobotomyRequestForm(target));
}
AForm* Intern::PresidentialPardon(std::string target)
{
	return(new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*func_ptr[3])(std::string) =
	{
		&Intern::ShrubberyCreation,
		&Intern::RobotomyRequest,
		&Intern::PresidentialPardon
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName)
		{
			return (this->*func_ptr[i])(formTarget);
		}
	}
	std::cout << "Invalid form name: " << formName << std::endl;
	return nullptr;
}