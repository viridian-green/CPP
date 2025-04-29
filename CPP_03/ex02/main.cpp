#include "FragTrap.hpp"

int main()
{
	ClapTrap Adele("Adele");
	FragTrap Dede("Dede");
	std::cout << "\n";
	// Dede.attack("Ines");
	// Dede.attack("Ines");
	// Dede.takeDamage(100);
	// Dede.attack("Ines");
	// Dede.attack("Ines");
	// Dede.beRepaired(1);
	// Dede.attack("Ines");
	// Dede.attack("Ines");
	// std::cout << "\n";
	Dede.highFivesGuys();
	int i = 0;
	while (i < 101)
	{
		Dede.attack("Ines");
		++i;
	}
}