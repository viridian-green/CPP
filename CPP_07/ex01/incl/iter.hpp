#pragma once

#include <aio.h>
#include <string>

template <typename iter>
void iter(int *A, size_t arraylen, std::function<int(int, int)> func) //understand how to use this
{
	for (int i = 0; i < arraylen; ++i)
	{
		f(A[i]);
	}
};
