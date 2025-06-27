#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include "string"
#include "iostream"

class Bureaucrat;

class AForm
{
    protected:
    std::string const name;
    bool isSigned;
    int const gradeSign;
    int const gradeExecute;

    public:
    AForm(std::string name, int gradeSign, int gradeExecute);
    AForm(const AForm &other);
    AForm& operator=(const AForm &other);
    ~AForm();
    std::string getName() const ;
    bool getFormStatus() const;
    int getGradetoSign() const;
    int getgradetoExecute() const;
	int execute(Bureaucrat const & executor) const;
	virtual void executeAction() const= 0;
    void beSigned(Bureaucrat &b);

    class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw()
			{
				return "Grade too high. Must be between 1 and 150.";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw()
			{
				return "The Bureaucrat's grade is too low to sign the Aform.";
			}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm &F);

#endif