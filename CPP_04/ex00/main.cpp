#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
//Here the object is deleted via a base class pointer
// A virtual destructor is critical in a base class when polymorphism is used, to ensure the entire object (base + derived part) is properly destroyed.
i->makeSound();
j->makeSound();
meta->makeSound();

delete i;
delete j;
delete meta;

const WrongAnimal* wrongAnimal = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();

std::cout << wrongAnimal->getType() << " " << std::endl;
std::cout << wrongCat->getType() << " " << std::endl;

wrongCat->makeSound();
wrongAnimal->makeSound();

delete wrongCat;
delete wrongAnimal;
return 0;
}