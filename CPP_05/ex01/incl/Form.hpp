#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    std::string const name;
    bool isSigned;
    int const gradeSign;
    int const gradeExecute;

    public:
    Form(std::string name, int gradeSign, int gradeExecute);
    Form(const Form &other);
    Form& operator=(const Form &other);
    ~Form();
    std::string getName() const ;
    bool getFormStatus() const;
    int getGradetoSign() const;
    int getgradetoExecute() const;
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
				return "The Bureaucrat's grade is too low to sign the form.";
			}
		};
};

std::ostream& operator<<(std::ostream& os, const Form &F);

#endif