#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed" << std::endl;
};

void Zombie::announce(void)
{
	std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& newName) {
	name = newName;
}



