#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <string>
#include <iostream>
#include "Zombie.hpp"


//Read Chatgpt chat 
class Zombie
{
	private:
	std::string name;

	public:
	Zombie(const std::string &inputname);
	~Zombie();
	void announce( void );

};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif