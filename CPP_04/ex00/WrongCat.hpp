#ifndef WRONG_CAT_H
# define WRONG_CAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private: 
    std:: string type;

    public:
    WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat& operator=(const WrongCat &other);
    ~WrongCat();
    void makeSound() const override;
};


#endif