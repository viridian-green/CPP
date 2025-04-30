#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "The Animal constructor is now called." << std::endl;
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}

Animal::~Animal()
{
    std::cout << "The Animal destructor is now called." << std::endl;
}