#include "Cat.hpp"


Cat::Cat() : type("Cat"), brain(new Brain())
{
    std::cout << "Cat construct!" << std::endl;
}

Cat::Cat(const Cat &other)
{
    delete brain;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meooooooow" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destruct!" << std::endl;
	delete brain;
}