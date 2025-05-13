#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "string"
#include "iostream"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	std::string getName() const ;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &F);
	void executeForm(AForm const & form) const;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat &B);

#endif