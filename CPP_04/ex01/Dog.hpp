#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
    std:: string type;
	Brain *brain;

    public:
    Dog();
    Dog(const Dog &other);
    Dog& operator=(const Dog &other);
    std::string getType() const override;
    void makeSound() const override;
    virtual ~Dog();
};


#endif