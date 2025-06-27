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

//Here I am not replacing ostream, I am simply extending it in order to print my Bureaucrat object data
//I amm explicitly stating how to print the Bureaucrat object
std::ostream& operator<<(std::ostream& os, const Bureaucrat &B)
{
	os << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat()
{}