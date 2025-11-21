#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <deque>
#include <time.h>
#include <chrono>

//I keep the original pair and will never break that relationship
struct Pair {
    int a;
    int b;
};

struct PairWithIndex {
    int main;
    int pend;
    size_t originalIndex;
};

class MergeSort{

	public:
	MergeSort();
	MergeSort(const MergeSort &oth);
	MergeSort &operator=(const MergeSort &oth);
	~MergeSort();

	int parseInputV(int ac, char **arg);
    int parseInputD(int ac, char **arg);
    void setDurVec(double input);
    void setDurDeq(double input);
    int getNbrComparaisons();
    std::vector<int> FJAlgoVec(std::vector<int> input);
    std::vector<int> getInput();
    std::vector<size_t> getOrder();
    std::vector<size_t> getJacobsthalOrder(size_t n);
    std::vector<size_t> generateJacobstahl(size_t n);
    void printResultV();

    std::deque<int> DgetInput();
    std::deque<int> FJAlgoDeq(std::deque<int> input);
    std::deque<size_t> DgetJacobsthalOrder(size_t n);
    void printResultD();

    private:
    std::vector<int> vec_sequence;
	std::vector<int> vec_result;
    std::deque<int> deq_sequence;
	std::deque<int> d_result;
    int m_comparaisons = 0;
    int m_leftover = 0;
    std::vector<size_t> order;
    std::deque<size_t> d_order;
    double dur_vec;
    double dur_deq;

};

