#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
    std::cout << "The AAnimal constructor is now called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string AAnimal::getType() const
{
    return type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal makes a sound" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "The AAnimal destructor is now called." << std::endl;
}