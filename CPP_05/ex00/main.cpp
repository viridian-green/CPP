#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Adele("Adele", -3);
	Bureaucrat lila("Adele", 2);

	lila.incrementGrade();
	lila.decrementGrade();
	lila.incrementGrade();
	lila.incrementGrade();

	std::cout << lila.getGrade();
}