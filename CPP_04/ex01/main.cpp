#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Dog basic;
	// Dog temp = basic;

	const Animal* animals[50];
	for (int i = 0; i < 25; i++)
	{
		animals[i] = new Cat();
		std::cout << i + 1 << std::endl;
	}
	for (int i = 25; i < 50; i++)
	{
		animals[i] = new Dog();
		std::cout << i + 1 << std::endl;
	}
	// Clean up dynamically allocated memory
	for (int i = 0; i < 50; i++)
	{
		delete animals[i];
	}

	//A shallow copy just copies the pointer to the Brain
	//But that means that both objects would hsare the same Brain in memory
	//or double deleting a pointer can cause a crash
}