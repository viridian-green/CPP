#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{

	if (grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
	{
		throw GradeTooHighException();
	}
	this->grade++;
}
void Bureaucrat::signForm(AForm &F)
{
	F.beSigned(*this);
	if (F.getFormStatus() == 1)
		std::cout << "Bureaucrat " << this->name << " signed " << F.getName() << std::endl;
	else
		std::cout << "Bureaucrat " << this->name << " couldn't sign " << F.getName() << " because their grade was too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.execute(*this) == 1)
		std::cout << "Bureaucrat " << this->name << " executed " << form.getName() << std::endl;
	else
		std::cout << "Bureaucrat " << this->name << " couldn't sign " << form.getName() << " because their grade was too low or the form was not signed prior" << std::endl;
}

Bureaucrat::~Bureaucrat()
{}

//Here I am not replacing ostream, I am simply extending it in order to print my Bureaucrat object data
//I amm explicitly stating how to print the Bureaucrat object
std::ostream& operator<<(std::ostream& os, const Bureaucrat &B)
{
	os << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}