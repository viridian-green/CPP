#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drrrrrrrrrrrrrrrrrrr" << std::endl;
	std::cout << "DRRRRRRRRRRRRRRRRR" << std::endl;
	std::cout << "IIIIIIIIIIIIIIIIIII" << std::endl;
	std::cout << "LLLLLLLLLLLLLLLLLL" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "Attention, " << this->target << "was robotimized successfully " << std::endl;
	else
		std::cout << "The robotomy of " << this->target << " has unfortunately failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}