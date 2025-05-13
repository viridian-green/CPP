#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExecute) : name(name), isSigned(0), gradeSign(gradeSign), 
gradeExecute(gradeExecute)
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

int Form::getGradetoSign() const
{
	return gradeSign;
}

int Form::getgradetoExecute() const
{
	return gradeExecute;
}

void Form::beSigned(Bureaucrat &B)
{
    if (B.getGrade() <= this->gradeSign)
        this->isSigned = 1;
    else 
        throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const Form& F)
{
    os << F.getName() << " form:" << std::endl;
    if (F.getFormStatus())
        os << "The form is signed." << std::endl;
    else
        os << "The form isn't yet signed." << std::endl;
    if (F.getGradetoSign() != 0)
        os << "The grade required to sign the form is " << F.getGradetoSign() << std::endl;
    else 
        os << "The grade required to sign the form is not yet initialized." << std::endl;
    if (F.getgradetoExecute() != 0)
        os << "The grade required to execute the form is " << F.getgradetoExecute() << std::endl;
    else 
        os << "The grade required to execute the form is not yet initialized." << std::endl;
    return os;
}

Form::~Form()
{}