#include "ScavTrap.hpp"

int main()
{
	ClapTrap Adele("Adele");
	ScavTrap Ines("Ines");
	// Ines.attack("Adele");
	// Ines.attack("Adele");
	// Ines.takeDamage(100);
	// Ines.attack("Adele");
	// Ines.attack("Adele");
	// Ines.beRepaired(50);
	// Ines.attack("Adele");
	// Ines.beRepaired(1);
	// Ines.guardGate();
	std::cout << "\n";
	Adele.attack("Ines");
	Adele.attack("Ines");
	Adele.takeDamage(10);
	Adele.attack("Ines");
	Adele.attack("Ines");
	Adele.beRepaired(8);
	Adele.attack("Ines");
	Adele.attack("Ines");
	int i = 0;
	while (i < 51)
	{
		Ines.attack("Adele");
		++i;
	}
}