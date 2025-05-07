#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
    std::string type;

    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal& operator=(const WrongAnimal &other);
    std::string getType() const;
    void makeSound() const;
    virtual ~WrongAnimal();
};

#endif