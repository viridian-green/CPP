#ifndef SCAVTAP_H
# define SCAVTAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
	static const int ENERGYPOINTS;

	public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void guardGate();
};


#endif