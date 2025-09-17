#include "../incl/iter.hpp"
#include <iostream>

int main()
{
float array[4] = {1, 2, 3, 4};
// int array[4] = {1, 2, 3, 4};

iter(array, 4, multiplyByTwo);

}