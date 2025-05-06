#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), type("WrongCat")
{
    std::cout << "WrongCat constructor!" << std::endl;
}


WrongCat::WrongCat(const WrongCat &other)
{
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor!" << std::endl;
}