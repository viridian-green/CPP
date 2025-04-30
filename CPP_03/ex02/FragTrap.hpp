#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
	static const int HITPOINTS;
    static const int ATTACKDAMAGE;

	public:
    FragTrap(const std::string name);
    FragTrap(const FragTrap &other);
    FragTrap operator=(const FragTrap &other);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif