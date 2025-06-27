#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class AForm;
class PresidentialPardonForm;

class Intern
{
	public:
	AForm *makeForm(std::string formName, std::string formTarget);
	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();
	AForm* ShrubberyCreation(std::string target);
	AForm* RobotomyRequest(std::string target);
	AForm* PresidentialPardon(std::string target);

};

#endif