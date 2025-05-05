#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
    std::cout << "The WrongAnimal constructor is now called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "The WrongAnimal makes a sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The WrongAnimal destructor is now called." << std::endl;
}