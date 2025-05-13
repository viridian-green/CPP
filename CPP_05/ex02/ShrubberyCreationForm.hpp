#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	const std::string target;

	public:
    ShrubberyCreationForm(const std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
	void execute(Bureaucrat const & executor) const;
};





#endif