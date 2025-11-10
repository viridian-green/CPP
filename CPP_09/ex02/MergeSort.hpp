#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <deque>
#include <set>


struct Pair {
    int a;
    int b;
};


class MergeSort{
	std::vector<int> m_vec_sequ;
	std::vector<int> m_pend_chain;
	std::vector<int> m_main_chain;
	std::deque<int> m_deque_sequ;
	int m_has_leftover;
	int m_leftover = 1;


	public:
	MergeSort();
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();
	void initContainers(const std::set<int>& input);
	int parseInput(int ac, char **arg);
	void VecJohnsonFord();
	void vectorAlgo();
	void sort();
	std::vector<int> vecJohnsonSort(std::vector<Pair>& pairs, bool hasLeftover, int leftoverValue);
	void printResult(std::vector<int> v);
	// void JacobstahlInsert();

};