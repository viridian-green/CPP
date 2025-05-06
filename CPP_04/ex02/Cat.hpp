#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
    std::string type;
	Brain *brain;

    public:
    Cat();
    Cat(const Cat &other);
    Cat& operator=(const Cat &other);
    void makeSound() const override;
    ~Cat();
};


#endif