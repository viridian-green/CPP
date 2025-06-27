#include "../incl/AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : name(name), isSigned(0), gradeSign(gradeSign),
gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign),
gradeExecute(other.gradeExecute)
{}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
	{
        this->isSigned = other.isSigned;
	}
	return (*this);
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getFormStatus() const
{
	return isSigned;
}

int AForm::getGradetoSign() const
{
	return gradeSign;
}

int AForm::getgradetoExecute() const
{
	return gradeExecute;
}

void AForm::beSigned(Bureaucrat &B)
{
    if (B.getGrade() <= this->gradeSign)
        this->isSigned = 1;
    else
        throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const AForm& F)
{
    os << F.getName() << " Aform:" << std::endl;
    if (F.getFormStatus())
        os << "The Aform is signed." << std::endl;
    else
        os << "The Aform isn't yet signed." << std::endl;
    if (F.getGradetoSign() != 0)
        os << "The grade required to sign the Aform is " << F.getGradetoSign() << std::endl;
    else
        os << "The grade required to sign the Aform is not yet initialized." << std::endl;
    if (F.getgradetoExecute() != 0)
        os << "The grade required to execute the Aform is " << F.getgradetoExecute() << std::endl;
    else
        os << "The grade required to execute the Aform is not yet initialized." << std::endl;
    return os;
}

int AForm::execute(Bureaucrat const & executor) const
{
	if (this->isSigned && executor.getGrade() <= this->getgradetoExecute())
	{
		executeAction();
		return 1;
	}
	else
	{
		throw std::runtime_error("The form cannot be executed because it either was not signed or the Bureaucrat's grade is too low.");
		return 0;
	}
}

AForm::~AForm()
{}