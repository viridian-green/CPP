#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    private: 
    std:: string type;

    public:
    Dog();
    Dog(const Dog &other);
    Dog& operator=(const Dog &other);
    ~Dog();
    void makeSound() const override;
    std::string getType() const override;
};


#endif