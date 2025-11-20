
#include "MergeSort.tpp"

// int main(int ac, char **av)
// {
// 	if (ac <= 1)
// 	{
// 		std::cerr << "Error. You must input name of program and your sequence" << std::endl;
// 		return 1;
// 	}

//     MergeSort vec;
// 	if (vec.parseInput(ac, av))
// 	{
// 		std::cerr << "Error. You must input a positive integer sequence" << std::endl;
// 		return 1;
// 	}
// 	vec.vec_duration();
//     vec.FJAlgo(vec.getInput());




//     // deq.FJalgo();
// 	vec.printResult();

// 	// MergeSort deq;

// }

#include "MergeSort.tpp"

int main(int argc, char** argv) {

    MergeSort<std::vector<int>> sorterVec;
    sorterVec.parseInput(argc, argv);
    auto inputVec = sorterVec.getInput();
	sorterVec.vec_duration();
    auto resultVec = sorterVec.FJAlgo(inputVec);
    sorterVec.printResult();

    MergeSort<std::deque<int>> sorterDeque;
    sorterDeque.parseInput(argc, argv);
    auto inputDeque = sorterDeque.getInput();
	sorterDeque.vec_duration();
    auto resultDeque = sorterDeque.FJAlgo(inputDeque);
    sorterDeque.printResult();

    return 0;
}