#ifndef AFORM_H
# define AFORM_H

#include "Bureaucrat.hpp"
#include "string"
#include "iostream"

class Bureaucrat;

class AForm
{
    private:
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
    virtual void beSigned(Bureaucrat &b) = 0;

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
				return "The Bureaucrat's grade is too low to sign the Aform.";
			}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm &F);

#endif