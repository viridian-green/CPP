#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "string"
#include "iostream"

class Bureaucrat
{
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	std::string getName(std::string name);
	int getGrade(int grade);
	int incrementGrade();
	int decrementGrade();
	~Bureaucrat();

	//These exception classes inherit from the standard c++ exception class
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const noexcept override
			{
				return "Grade too high. Must be between 1 and 150.";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Grade too low. Must be between 1 and 150.";
			}
		};
};

#endif