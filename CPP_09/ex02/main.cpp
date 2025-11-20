#include "MergeSort.tpp"

int main(int argc, char** argv) {

    MergeSort<std::vector<int>> sorterVec;
    sorterVec.parseInput(argc, argv);
    auto inputVec = sorterVec.getInput();
    auto start = std::chrono::high_resolution_clock::now();
    auto resultVec = sorterVec.FJAlgo(inputVec);
    auto end = std::chrono::high_resolution_clock::now();
    sorterVec.setDurVec(std::chrono::duration<double>(end - start).count());
    sorterVec.printResult();

    MergeSort<std::deque<int>> sorterDeque;
    sorterDeque.parseInput(argc, argv);
    auto inputDeque = sorterDeque.getInput();
    start = std::chrono::high_resolution_clock::now();
    auto resultDeque = sorterDeque.FJAlgo(inputDeque);
    end = std::chrono::high_resolution_clock::now();
    sorterDeque.setDurDeq(std::chrono::duration<double>(end - start).count());
    sorterDeque.printResult();

    return 0;
}