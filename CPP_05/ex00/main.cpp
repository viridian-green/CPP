#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat Adele("Adele", -3);
	Bureaucrat lila("Adele", 3);

	lila.incrementGrade();

	std::cout << lila.getGrade();
}