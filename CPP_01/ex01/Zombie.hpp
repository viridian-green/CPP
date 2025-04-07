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
	Zombie() : name("") {}
	Zombie(const std::string &inputname);
	~Zombie();
	void announce( void );
	void setName(const std::string& newName);
};

Zombie* zombieHorde( int N, std::string name );

#endif