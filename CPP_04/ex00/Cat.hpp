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
    std::string getType() const override;
    void makeSound() const override;
    ~Cat();
};


#endif