#include "FragTrap.hpp"

const int FragTrap::HITPOINTS = 100;
const int FragTrap::ATTACKDAMAGE = 30;

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap default constructor is called" << std::endl;
    this->_type = "FragTrap";
	this->HitPoints = HITPOINTS;
	this->EnergyPoints = 100;
	this->AttackDamage = ATTACKDAMAGE;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    this->name = other.name;
    this->_type = other._type;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
}

FragTrap FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
    std::cout << "FragTrap default destructor is called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap is requesting high fives!" << std::endl;
}