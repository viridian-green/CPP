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
}; //DO WE STILL NEED THIS?

template <typename Container>
class MergeSort{
    Container m_sequence;
	Container m_result;
	std::vector<Pair> m_pair;
    int form_pairs = -1;
	// std::vector<int> main_chain; // bigger number from the pair
	// std::vector<int> pend_chain;  // smaller number from the pair

	public:
	// MergeSort();
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();
	void initContainers(const std::set<int>& input);
	int parseInput(int ac, char **arg);
	void VecJohnsonFord();
	void sort();
	Container FJalgo();
	void printResult(std::vector<int> v);
    void mergeSort(const Container& input, Container& main_chain,  Container& pend_chain);
    void binarySearch();
	Container getResult();
    Container getInput();
	std::vector<size_t> jacobsthalOrder(size_t n);

};

template <typename Container>
void MergeSort<Container>::mergeSort(const Container& input, Container& main_chain,  Container& pend_chain)
{
    typedef typename Container::const_iterator const_it;
    typedef typename Container::value_type value_type;

    if (input.size() <= 2) {
        for (const_it it = input.begin(); it != input.end(); ++it)
            main_chain.push_back(*it);
        return;
    }

    const_it it = input.begin();
    while (it != input.end()) {
        value_type first = *it;
        ++it;
        if (it == input.end()) {
            pend_chain.push_back(first);
            break;
        }
        value_type second = *it;
        ++it;
        if (first < second)
            std::swap(first, second);
        main_chain.push_back(first);
        pend_chain.push_back(second);
        if (!form_pairs)
        {
        m_pair.push_back(std::make_pair(first, second));
        form_pairs = 1;
        }
    }
    Container new_main, new_pend;

    mergeSort(main_chain, new_main, new_pend);
    main_chain = new_main;

    pend_chain.insert(pend_chain.end(), new_pend.begin(), new_pend.end());
}


template <typename Container, typename T>
typename Container::const_iterator binarySearch(const Container& container, const T& value)
{
    auto left = container.begin();
    auto right = container.end();

    while (left < right) {
        // find the middle iterator
        auto mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (*mid == value)
            return mid; // found
        else if (*mid < value)
            left = std::next(mid); // search right half
        else
            right = mid;           // search left half
    }

    return container.end(); // not found
}

template <typename Container>
Container MergeSort<Container>::FJalgo() {

    Container main_chain;
    Container pend_chain;
    mergeSort(m_sequence, main_chain, pend_chain);

     for (typename Container::value_type x : main_chain) {
        std::cout << x << ". ";
    } std::cout << "\n";

         for (typename Container::value_type x : pend_chain) {
        std::cout << x << "< ";
    } std::cout << "\n";

    Container order = jacobsthalOrder(pend_chain.size());


    return (main_chain);
}

template <typename Container>
void MergeSort<Container>::printResult(std::vector<int> v)
{
	std::cout << "Before: ";
	for (int x : m_sequence) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	std::cout << "After: ";
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	//TODO: Implement the printing of the time
}

template <typename Container>
int MergeSort<Container>::parseInput(int ac, char **arg) {

	for (int i = 1; i < ac; i++)
	{
		std::string token = arg[i];
		if (::isdigit(token[0]))
		{
			int value = std::stoi(token.c_str());
			if (std::find(m_sequence.begin(), m_sequence.end(), value) == m_sequence.end()  && value >= 0)
			{
				m_sequence.push_back(std::atoi(token.c_str()));
			}
		}
		else
			return 1;
	}
    if (m_sequence.size() == 1)
        printResult(m_sequence);
	return 0;
};


