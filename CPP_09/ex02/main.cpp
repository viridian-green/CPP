
#include "MergeSort.hpp"

int main(int ac, char **av)
{
	MergeSort<std::vector<int>> vec;
    MergeSort<std::deque<int>> deq;
	if (ac <= 1)
	{
		std::cerr << "Error. You must input name of program and your sequence" << std::endl;
		return 1;
	}
	if (vec.parseInput(ac, av))
	{
		std::cerr << "Error. You must input a positive integer sequence" << std::endl;
		return 1;
	}

	vec.FJalgo();
    deq.FJalgo();
	// vec.printResult(vec.getResult());


//TODO: Debug for the number of operations
}