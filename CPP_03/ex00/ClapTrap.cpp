#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
  : name(name)
  , HitPoints(10)
  , EnergyPoints(10)
  , AttackDamage(10)
{
    std::cout << "ClapTrap “" << name << "” constructor is called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) :
name(other.name),
HitPoints(other.HitPoints),
EnergyPoints(other.EnergyPoints),
AttackDamage(other.AttackDamage){}

ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
				  << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has no energy left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 1)
		std::cout << "ClapTrap " << this->name << " regains " << amount << " energy point" << std::endl;
	std::cout << "Claptrap " << this->name << " loses " << amount << " energy points" << std::endl;
	if (amount == this->EnergyPoints)
		std::cout << this->name << " has no more Energy points." << this->name << " dies" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 1)
		std::cout << "ClapTrap " << this->name << " regains " << amount << " hit point" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " regains " << amount << " hit points" << std::endl;
	this->HitPoints += amount;
	this->EnergyPoints--;
}

