#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    private: 
    std:: string type;

    public:
    Cat();
    Cat(const Cat &other);
    Cat& operator=(const Cat &other);
    void makeSound() const override;
    ~Cat();
};


#endif