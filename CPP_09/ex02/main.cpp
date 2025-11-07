
#include "MergeSort.hpp"

int main(int ac, char **av)
{
	MergeSort ms;
	if (ac <= 1)
	{
		std::cerr << "Error. You must input name of program and your sequence" << std::endl;
		return 1;
	}
	if (ms.parseInput(ac, av))
	{
		std::cerr << "Error. You must input a positive integer sequence" << std::endl;
		return 1;
	}
	// ms.VecAlgorithm();
}