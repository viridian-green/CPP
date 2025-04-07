#include "Zombie.hpp"

Zombie::Zombie(const std::string &inputname)
{
	this->name = inputname;
};

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed" << std::endl;
};
void Zombie::announce(void)
{
	std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}



