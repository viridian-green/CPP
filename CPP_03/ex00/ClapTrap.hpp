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
    ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(ClapTrap const &other);
    ~ClapTrap();

};


#endif