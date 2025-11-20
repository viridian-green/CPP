
#include "MergeSort.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr << "Error. You must input name of program and your sequence" << std::endl;
		return 1;
	}

    MergeSort vec;
    MergeSort deq;
	if (vec.parseInputV(ac, av))
	{
		std::cerr << "Error. You must input a positive integer sequence" << std::endl;
		return 1;
	}

	auto start = std::chrono::high_resolution_clock::now();
    vec.FJAlgoVec(vec.getInput());
    auto end = std::chrono::high_resolution_clock::now();
    vec.setDurVec(std::chrono::duration<double>(end - start).count());
    // vec.printResultV();

    // if (deq.parseInputD(ac, av))
	// {
	// 	std::cerr << "Error. You must input a positive integer sequence" << std::endl;
	// 	return 1;
	// }

    start = std::chrono::high_resolution_clock::now();
    deq.FJAlgoDeq(deq.DgetInput());
    end = std::chrono::high_resolution_clock::now();
    deq.setDurDeq(std::chrono::duration<double>(end - start).count());
	vec.printResultD();

}