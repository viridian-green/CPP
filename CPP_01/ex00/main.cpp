#include "Zombie.hpp"

/* In this function we can allocate memory in two different ways.
The first one is by using a stack (dynamic allocation) - which uses new and delete and is faster-
The second one is using heap --> slower
*/
int main()
{
	Zombie manager("manager");
	Zombie *bobTheZombie = manager.newZombie("Biba");
	bobTheZombie->announce();
	manager.randomChump("RandomChamp");
	delete(bobTheZombie);
}