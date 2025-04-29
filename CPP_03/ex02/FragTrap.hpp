#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap(const std::string name);
    FragTrap(const FragTrap &other);
    FragTrap operator=(const FragTrap &other);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif