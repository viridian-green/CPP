#ifndef PRESIDENTIAL_H
# define PRESIDENTIAL_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string target;

	public:
    PresidentialPardonForm(const std::string name);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
	void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
};

#endif