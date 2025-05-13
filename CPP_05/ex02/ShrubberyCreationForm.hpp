#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    ShrubberyCreationForm(const std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
};





#endif