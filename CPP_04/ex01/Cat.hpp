#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
    std::string type;
	Brain *brain;

    public:
    Cat();
    Cat(const Cat &other);
    Cat& operator=(const Cat &other);
    std::string getType() const override;
    void makeSound() const override;
    virtual ~Cat();
};


#endif