#pragma once


template <typename T>
int easyfind(T haystack, int needle)
{
	std::T<haystack>::iterator it = std::find(haystack.begin(), haystack.end(), needle);

	if (std::find(haystack.begin(), haystack.end(), needle) != haystack.end() )
   		std::cout << "found integer " << needle << " in container!" <<std::endl;
	else
   		return -1;
	return 1;
}
