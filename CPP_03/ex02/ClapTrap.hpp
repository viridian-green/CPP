#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

//I needed ot change atrtibutes to protected, not private,
//in order to allow other classes to inherit this code
class ClapTrap
{
	//I switched the attributes to protected and added
	//a string type is added allow malleability of 
	//ScavTrap functions instead of having them hardcoded
	protected:
	std::string name;
	int HitPoints = 10;
	int EnergyPoints = 10;
	int AttackDamage = 10;
	std::string _type;

	public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other); 
	ClapTrap& operator=(ClapTrap const &other);
	~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif