#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

class DiamondTrap : public ScavTrap, public FragTrap 
{
    private:
    std::string name;

    public:
    AttackDamage = ScavTrap::preset;
    void whoAmI();
};

#endif