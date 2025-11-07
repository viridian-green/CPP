#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <deque>
#include <set>


struct Pair
{
	int a;
	int b;
};


class MergeSort{
	std::vector<int> m_vec_sequ;
	std::vector<int> m_pend_chain;
	std::vector<int> m_main_chain;
	std::deque<int> m_deque_sequ;

	public:
	// MergeSort();
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();
	void initContainers(const std::set<int>& input);
	int parseInput(int ac, char **arg);
	void VecJohnsonFord();
	void makeOriginalPairs();
	void sort();

	// void JacobstahlInsert();

};