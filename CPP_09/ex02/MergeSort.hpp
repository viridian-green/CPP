#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <deque>
#include <set>

//I keep the original pair and will never break that relationship
struct Pair {
    int a; //bigger number: on the left of pair
    int b; //smaller number: on the right of pair
};


class MergeSort{
	std::vector<int> m_vec_sequ;
	std::deque<int> m_deque_sequ;
	std::vector<int> m_result;
	int m_has_leftover;
	int m_leftover = -1;
	int m_has_newleftover = -1;
	int m_newleftover = -1;

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
	std::vector<int> vecJohnsonSort(std::vector<int>& pairs, bool hasLeftover, int leftoverValue);
	void printResult(std::vector<int> v);
	std::vector<int> getResult();
	// void JacobstahlInsert();

};