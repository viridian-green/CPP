#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
    std::string name;

    public:
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap operator=(const DiamondTrap &other);
	~DiamondTrap();
    void whoAmI();
};

#endif