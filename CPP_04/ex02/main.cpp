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
	//AAnimal A;  
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();	

	delete i;
	delete j;
}

