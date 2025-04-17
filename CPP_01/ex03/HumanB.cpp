#include "HumanB.hpp"

HumanB::~HumanB(){};

HumanB::HumanB(std::string name)
: name(name), weapon(0)
{
};

void HumanB::setWeapon(Weapon &type)
{
	weapon = &type;
}

void HumanB::attack()
{
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}