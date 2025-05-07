#include "Cat.hpp"

Cat::Cat() : Animal(), type("Cat")
{
    std::cout << "Cat construct!" << std::endl;
}

Cat::Cat(const Cat &other)
{
    this->type = other.type;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Cat::getType() const
{
    return type;
}


void Cat::makeSound() const
{
    std::cout << "Meooooooow" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destruct!" << std::endl;
}