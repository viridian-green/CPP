#include "easyfind.hpp"
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v1 = {1, 2, 3, 4};


	v1.push_back(5);
	v1.push_back(6);
	v1[0] = 24;

	easyfind(v1, 24);
}