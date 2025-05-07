#include "ScavTrap.hpp"

int main()
{
	ClapTrap Adele("Adele");
	ScavTrap Ines("Ines");
	std::cout << "\n";
	Adele.attack("Ines");
	Adele.attack("Ines");
	Adele.takeDamage(10);
	Adele.attack("Ines");
	Adele.attack("Ines");
	Adele.beRepaired(8);
	Adele.attack("Ines");
	int i = 0;
	while (i < 51)
	{
		Ines.attack("Adele");
		++i;
	}
	Ines.guardGate();
}