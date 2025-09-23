#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <exception>

int main()
{
	try
	{
	std::vector<int> v1 = {1, 2, 3, 4};

	v1.push_back(5);
	v1.push_back(6);
	v1[0] = 24;

	v1.push_back(5);
	v1.push_back(6);

	easyfind(v1, 24);

	std::list<int> v2 = {1, 2, 3, 4};

	v2.push_back(5);
	v2.push_back(6);

	easyfind(v2, 24);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int> v2 = {1, 2, 3, 4};

		v2.push_back(5);
		v2.push_front(6);

		easyfind(v2, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		std::deque<int> v2 = {1, 2, 3, 4};

		v2.push_back(5);
		v2.push_front(6);

		easyfind(v2, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}