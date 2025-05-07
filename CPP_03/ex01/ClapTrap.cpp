#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
  : name(name)
  ,_type("ClapTrap")
  , HitPoints(10)
  , EnergyPoints(10)
  , AttackDamage(0)
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
	if (this->EnergyPoints <= 0)
		std::cout << _type << " " << this->name << " has no energy left to attack!" << std::endl;
	else if (this->HitPoints <= 0)
		std::cout << _type << " " << this->name << " has too few hit points to attack!" << std::endl;
	else
	{
	std::cout << _type << " " << this->name << " attacks " << target
				  << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 1)
		std::cout << _type << " " << this->name << "takes damage and loses " << amount << " hit point" << std::endl;
	std::cout << _type << " " << this->name << " takes damage and loses " << amount << " hit points" << std::endl;
	if (amount > this->HitPoints)
		std::cout << this->name << " has no more hit points." << " game over" << std::endl;
	this->HitPoints = HitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 1)
		std::cout << _type << " " << this->name << " is repaired and regains " << amount << " hit point" << std::endl;
	else
		std::cout << _type << " " << this->name << " is repaired and regains " << amount << " hit points" << std::endl;
	this->HitPoints = HitPoints + amount;
	this->EnergyPoints--;
}

