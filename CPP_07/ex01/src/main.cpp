#include "../incl/iter.hpp"
#include <iostream>

template <typename T>
void iter(T *array, size_t arraylen, void (*func)(T &element))
{
	for (size_t i = 0; i < arraylen; ++i)
	{
		func(array[i]);
	}
}

template <typename T>
void multiplyByTwo(T &i)
{
    std::cout << i*2<< std::endl;
}

int main()
{
float array[4] = {1, 2, 3, 4};
// int array[4] = {1, 2, 3, 4};

iter(array, 4, multiplyByTwo); //the function pointer is instantiated here


}