#include "FragTrap.hpp"

int main()
{
	ClapTrap Adele("Adele");
	FragTrap Dede("Dede");
	std::cout << "\n";
	int i = 0;
	while (i < 101)
	{
		Dede.attack("Ines");
		++i;
	}
	Dede.highFivesGuys();
}