#ifndef SHRUBBERYCREATION_H
# define SHRUBBERYCREATION_H

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
	void executeAction() const;
};

#endif