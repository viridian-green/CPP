#include "DiamondTrap.hpp"

//Making them static const means their value will never change
//Both FragTrap and ScavTrap inherit from ClapTrap. So when DiamondTrap
//inherits from both of them, it ends up with two copies of ClapTrap — one from each path.
//the vitual keyword crates a shared base class


//DiamondTrap is responsible for constructing the ClapTrap constructorr
DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "Default DiamondTrap constructor is called";
	this->name = name;
	this->_type = _type;
    this->HitPoints = FragTrap::HITPOINTS;
    this->EnergyPoints = ScavTrap::ENERGYPOINTS;
    this->AttackDamage = FragTrap::ATTACKDAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->name = other.name;
	this->_type = other._type;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
	this->name = other.name;
	this->_type = other._type;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Default DiamondTrap destructor is called";
}

void DiamondTrap::whoAmI()
{

}