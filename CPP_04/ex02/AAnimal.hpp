#ifndef AANIMAL_H
# define AANIMAL_H
#include <string>
#include <iostream>

class AAnimal
{
    protected:
    std::string type;

    public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal& operator=(const AAnimal &other);
    std::string getType() const;
    virtual void makeSound() const = 0;
    virtual ~AAnimal();

};

#endif