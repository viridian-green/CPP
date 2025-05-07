#include "Dog.hpp"

Dog::Dog() : Animal(), type("Dog")
{
    std::cout << "Dog constructor!" << std::endl;
}


Dog::Dog(const Dog &other)
{
    this->type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor!" << std::endl;
}