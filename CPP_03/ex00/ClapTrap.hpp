#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:
	std::string name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;

	public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(ClapTrap const &other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif