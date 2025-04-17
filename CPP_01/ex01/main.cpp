#include "Zombie.hpp"

/* In this function we can allocate memory in two different ways.
The first one is by using a stack (dynamic allocation) - which uses new and delete and is faster-
The second one is using heap --> slower
*/
int main()
{
	int N = 5;
	Zombie z("z");
	Zombie *horde = z.zombieHorde(5, "Gabrielle");
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}