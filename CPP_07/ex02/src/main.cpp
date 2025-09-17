#include <iostream>
#include "../incl/Array.hpp"

int main()
{
	Array<int> empty;
	std::cout << "Size of empty is: " << empty.size() << std::endl;

	Array<std::string> string_arr(2);
	string_arr[0] = "hi";
	string_arr[1] = "world";

	std::cout << "Size of string_arr is: " << string_arr.size() << std::endl;
	std::cout << string_arr[1] << std::endl;

	 try {

		Array<int> firstArr(5);
    	firstArr[4] = 6;
		firstArr[8] = 6;
    	std::cout << firstArr[4] << std::endl;

		std::cout << firstArr[7] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
    }

	 try {

		Array<int> secondArr(2);
    	secondArr[1] = 3;

		std::cout << secondArr[1] << std::endl;

    	std::cout << "Size of secondArr is: " << secondArr.size() << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
    }
}