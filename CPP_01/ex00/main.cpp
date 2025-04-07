#include "Zombie.hpp"

/* In this function we can allocate memory in two different ways.
The first one is by using a stack (dynamic allocation) - which uses new and delete and is faster-
The second one is using heap --> slower
*/
int main()
{
	Zombie *z1 = newZombie("BrainEater");
	randomChump("LegEater");

	delete z1;
}