#include "Dog.hpp"

Dog::Dog() : Animal(), type("Dog"), brain(new Brain())
{
    std::cout << "Dog constructor!" << std::endl;
}


Dog::Dog(const Dog &other)
{
    this->type = other.type;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
		delete this->brain;
        brain = new Brain(*other.brain);

    }
    return (*this);
}


void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

std::string Dog::getType() const
{
    return type;
}

Dog::~Dog()
{
    std::cout << "Dog destructor!" << std::endl;
	delete brain;
}