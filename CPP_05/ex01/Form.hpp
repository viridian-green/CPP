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
    int getGradeSigned() const;
    int getgradeExecute() const;
    void beSigned(Bureaucrat B);

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
				return "Your grade is lower than 150 or lower than the required grade to sign the form.";
			}
		};
};

std::ostream& operator<<(std::ostream& os, const Form &F);

#endif