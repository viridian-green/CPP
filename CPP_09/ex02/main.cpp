#include "MergeSort.tpp"

int main(int argc, char** argv) {

    MergeSort<std::vector<int>> sorterVec;
    sorterVec.parseInput(argc, argv);
	sorterVec.vec_duration();
    sorterVec.printResult();

    MergeSort<std::deque<int>> sorterDeque;
    sorterDeque.parseInput(argc, argv);
	sorterDeque.deq_duration();
    sorterDeque.printResult();

    return 0;
}