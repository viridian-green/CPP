
#include "MergeSort.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr << "Error. You must input name of program and your sequence" << std::endl;
		return 1;
	}

    MergeSort vec;
	if (vec.parseInput(ac, av))
	{
		std::cerr << "Error. You must input a positive integer sequence" << std::endl;
		return 1;
	}

    vec.FJAlgo(vec.getInput());

	std::cout << "Comparaisons used :" << vec.getNbrComparaisons() << std::endl;
    // deq.FJalgo();
	// vec.printResult();

	// MergeSort deq;

}