#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExecute) : name(name), isSigned(0),gradeSign(0), 
gradeExecute(0)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), 
gradeExecute(other.gradeExecute)
{}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
	{
        this->isSigned = other.isSigned;
	}
	return (*this);
}

std::string Form::getName() const 
{
	return name;
}

bool Form::getFormStatus() const
{
	return isSigned;
}

int Form::getGradeSigned() const
{
	return gradeSign;
}

int Form::getgradeExecute() const
{
	return gradeExecute;
}

void Form::beSigned(Bureaucrat B)
{
    if (B.getGrade() >= this->gradeSign)
        this-> isSigned = 1;
    else 
        throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const Form& form)
{

}

Form::~Form()
{}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &B)
{
	os << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}