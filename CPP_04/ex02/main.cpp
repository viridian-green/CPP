#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//Since the Animal class doesn't mean anything
//to instantiaze it on its own 

//So let's make it abstract : to do this we create 
//at least one pure virtual function 

//A pure virtual function 
int main()
{
	//I cannot instatiate an Animal project anymore
	//AAnimal test;  
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " is my type, says j" << std::endl;
	std::cout << i->getType() << " is my type, says i" << std::endl;
	i->makeSound();
	j->makeSound();	

	delete i;
	delete j;
}

