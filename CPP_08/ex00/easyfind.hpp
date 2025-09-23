#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>

//An associate container stores data in sorted order (set, map,)
template <typename T>
void easyfind(T haystack, int needle)
{
	typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);

	if (std::find(haystack.begin(), haystack.end(), needle) != haystack.end() )
   		std::cout << "Found integer " << needle << " with type : " << typeid(T).name() <<std::endl;
	else
   		throw std::runtime_error("Error. Needle nowhere to be found in haystack");
}
