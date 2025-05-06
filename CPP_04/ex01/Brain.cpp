#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain construct is called" << std::endl;
}
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}
Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
		this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destruct is called" << std::endl;
}