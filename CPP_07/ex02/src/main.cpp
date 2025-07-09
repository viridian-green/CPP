#include <iostream>
#include "../incl/Array.hpp"

int main()
{
    int t;
    //I cannot instantiate an object here without it being interpreted as a function
    //declaration
    Array<int> firstArr(5);
    firstArr[4] = 6;
    std::cout << firstArr[4] << std::endl;
}