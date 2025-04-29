#include "ScavTrap.hpp"

const int ScavTrap::ENERGYPOINTS = 50;
//When you call a constructor the compiler
//sets up the memory allocation for the object
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap default constructor is called" << std::endl;
	this->_type = "ScavTrap";
	this->HitPoints = 100;
	this->EnergyPoints = ENERGYPOINTS;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor is called" << std::endl;
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}