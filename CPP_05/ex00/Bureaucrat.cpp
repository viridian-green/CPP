#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try
	{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	this->grade = grade;
	}
	catch (std::exception & e)
	{
		//Here I am calling the what function from the Exception libraries
		std::cerr << "Exception: " << e.what() << std::endl;
	}
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

std::string Bureaucrat::getName(std::string name)
{
	return name;
}
int Bureaucrat::getGrade(int grade)
{
	return grade;
}

int Bureaucrat::incrementGrade()
{
	try
	{
	if (grade == 1)
		throw "Error. Incrementing grade will make it out of range";
	grade--;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error. Incrementing grade will make it our of range";
	}
}

// int Bureaucrat::decrementGrade()
// {
// 	try
// 	{
// 	if (grade == 150)
// 	{
// 		throw "Error. Incrementing grade will make it our of range";
// 	}
// 	grade++;
// 	}
// 	catch (std::exception & e)
// 	{

// 	}
// }

Bureaucrat::~Bureaucrat()
{}