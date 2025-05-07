#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
    std:: string type;
	Brain *brain;

    public:
    Dog();
    Dog(const Dog &other);
    Dog& operator=(const Dog &other);
    ~Dog();
    std::string getType() const override;
    void makeSound() const override;
};


#endif