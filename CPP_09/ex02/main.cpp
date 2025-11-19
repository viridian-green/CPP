
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
	vec.vec_duration();
    vec.FJAlgo(vec.getInput());

	
    std::cout << "order: ";
	for (size_t x : vec.getOrder()) {
		std::cout << x + 1 << ".";
	}

    // deq.FJalgo();
	// vec.printResult();

	// MergeSort deq;

}