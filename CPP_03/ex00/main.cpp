#include "ClapTrap.hpp"

#include <iostream>

int main()
{
	ClapTrap Adele("Adele");
	Adele.attack("Ines");
	Adele.takeDamage(3);
	Adele.attack("Ines");
	Adele.takeDamage(10);
	Adele.attack("Ines");
	Adele.beRepaired(1);
	Adele.attack("Ines");
}