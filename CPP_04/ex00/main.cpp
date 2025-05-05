#include "Animal.hpp"
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
return 0;
}