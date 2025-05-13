#ifndef ROBOTOMY_H
# define ROBOTOMY_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	std::string target;

	public:
    RobotomyRequestForm(const std::string name);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
	void executeAction() const;
    ~RobotomyRequestForm();
};

#endif