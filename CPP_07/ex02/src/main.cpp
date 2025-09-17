#include <iostream>
#include "../incl/Array.hpp"

int main()
{
	 try {

		Array<int> firstArr(5);
    	firstArr[4] = 6;

    	std::cout << firstArr[4] << std::endl;

		std::cout << firstArr[7] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
    }

	 try {

		Array<int> secondArr(2);
    	secondArr[1] = 3;

    	std::cout << "Size of secondArr is: " << secondArr.size() << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
    }
}