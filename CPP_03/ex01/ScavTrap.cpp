#include "ScavTrap.hpp"


//When you call a constructor the compiler
//sets up the memory allocation for the object
ScavTrap::ScavTrap(const std::string name) : ClapTrap("ScavTrap"), name(name), 
{
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){}


ScavTrap::ScavTrap operator=(const ScavTrap& other){}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor is called" << std::endl;
}