#include "Cat.hpp"


Cat::Cat() : Animal(), type("Cat"), brain(new Brain())
{
    std::cout << "Cat construct!" << std::endl;
}

Cat::Cat(const Cat &other)
{
    this->type = other.type;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meooooooow" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}

Cat::~Cat()
{
    std::cout << "Cat destruct!" << std::endl;
	delete brain;
}