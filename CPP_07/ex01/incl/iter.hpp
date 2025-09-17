#pragma once

#include <aio.h>
#include <string>
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
