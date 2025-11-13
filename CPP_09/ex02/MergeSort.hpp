#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <deque>
#include <set>

// //I keep the original pair and will never break that relationship
// struct Pair {
//     int a; //bigger number: on the left of pair
//     int b; //smaller number: on the right of pair
//     // Pair(int x, int y) : a(x), b(y) {}
// };

struct FirstPair {
    int main_val;   // bigger number
    size_t pend_idx; // index of corresponding pend element
};

template <typename Container>
class MergeSort{

	public:
	MergeSort();
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();
     typedef typename Container::value_type value_type;
	void initContainers(const std::set<int>& input);
	int parseInput(int ac, char **arg);
	void VecJohnsonFord();
	void sort();
	void FJalgo();
	void printResult();

void mergeSort(Container& input,
                                     Container& main_chain,
                                     Container& pend_chain, std::vector<FirstPair>* first_pairs = nullptr);
    void binarySearch();
	Container getResult();
    Container getInput();
	Container jacobsthalOrder(size_t n);

    private:
    Container m_sequence;
	Container m_result;
    // std::vector<Pair> pairs;
    std::vector<size_t> partner_indices;
    // Container::<std::Pair<int, int>> pairs;
    int form_pairs = -1;
    // std::vector<FirstPair> *first_pairs = nullptr;

};


template <typename Container>
MergeSort<Container>::MergeSort() : m_result{-1} {}

template <typename Container>
Container MergeSort<Container>::jacobsthalOrder(size_t n) {
    Container order;
    if (n == 0)
        return order;
    Container jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n - 1)
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);

    // The FJ algorithm uses Jacobsthal gaps to define insertion indices
    size_t last = 1;
    while (last < n) {
        size_t next = jacob[last];
        if (next > n - 1)
            next = n - 1;
        for (size_t i = next; i > jacob[last - 1]; --i)
            order.push_back(i);
        ++last;
    }

    return order;
};

// template <typename Container>
// void MergeSort<Container>::mergeSort(Container& input, Container& main_chain,  Container& pend_chain)
// {

//     auto it = input.begin();
//     while (it != input.end()) {
//         auto first = *it;
//         ++it;
//           if (it == input.end()) {
//             pend_chain.push_back(first);
//             break;
//         }
//         if (input.size() == 3)
//         {
//             pend_chain.push_back(input.back());
//             input.pop_back();
//         }
//         auto second = *it;
//         ++it;
//         if (first < second)
//             std::swap(first, second);
//         if (input.size() <= 2) {
//             main_chain.push_back(second);
//             main_chain.push_back(first);
//             return;
//         }
//         main_chain.push_back(first);
//         pend_chain.push_back(second);
//         partner_indices.push_back(i);

//     }
//     Container new_main, new_pend;
//     // form_pairs = 1;
//     mergeSort(main_chain, new_main, new_pend);
//     main_chain = new_main;

//     pend_chain.insert(pend_chain.end(), new_pend.begin(), new_pend.end());
// }

// template <typename Container>
// void MergeSort<Container>::FJalgo() {

//     if (m_sequence.size() == 1)
//         return;

//     Container main_chain;
//     Container pend_chain;
//     mergeSort(m_sequence, main_chain, pend_chain);


//     Container order = jacobsthalOrder(pend_chain.size());
//       for (typename Container::value_type x : main_chain) {
//         std::cout << x << ". ";
//     } std::cout << "\n";

//          for (typename Container::value_type x : pend_chain) {
//         std::cout << x << "< ";
//     } std::cout << "\n";

//     for (size_t idx : order) {
//         int val = pend_chain[idx];
//         std::cout << val << std::endl;
//         // find its corresponding main partner
//         int partner = partner_indices[idx].a;
//         std::cout << partner << std::endl;
//         // binary search upper bound for where to insert val
//         auto pos = std::upper_bound(main_chain.begin(), main_chain.end(), partner);
//         main_chain.insert(pos, val);
//     }

//     std::cout << "After: ";
// 	for (int x : main_chain) {
// 		std::cout << x << " ";
// 	}

//     m_result = main_chain;
// }

template <typename Container>
void MergeSort<Container>::mergeSort(Container& input,
                                     Container& main_chain,
                                     Container& pend_chain, std::vector<FirstPair>* first_pairs)

{
    auto it = input.begin();
    size_t pair_idx = 0;

    while (it != input.end()) {
        auto first = *it++;
        // if (it == input.end()) {
        //     pend_chain.push_back(first);
        //     if (first_pairs) first_pairs->push_back({first, pair_idx-1});
        //     break;
        // }

        auto second = *it++;
        if (first < second) std::swap(first, second);

        main_chain.push_back(first);
        pend_chain.push_back(second);

        if (first_pairs) {
            first_pairs->push_back({first, pair_idx});
        }
        pair_idx++;
    }

    // Recurse on main_chain
    if (main_chain.size() > 2) {
        Container new_main, new_pend;
        mergeSort(main_chain, new_main, new_pend);
        main_chain = new_main;
        pend_chain.insert(pend_chain.end(), new_pend.begin(), new_pend.end());
    }
}

template <typename Container>
void MergeSort<Container>::FJalgo()
{
    if (m_sequence.size() <= 1) return;

    Container main_chain, pend_chain;

    std::vector<FirstPair> first_pairs = nullptr;

    mergeSort(m_sequence, main_chain, pend_chain,  &first_pairs);

    Container order = jacobsthalOrder(pend_chain.size());

    for (size_t idx : order) {
        int val = pend_chain[idx];
        // find original main partner from first_pairs
        // int partner = first_pairs[idx].main_val;

        // auto pos = std::upper_bound(main_chain.begin(), main_chain.end(), partner);
        // main_chain.insert(pos, val);
    }

    m_result = main_chain;
}

template <typename Container>
void MergeSort<Container>::printResult()
{
    if (m_result[0] == -1)
        m_result = m_sequence;

	std::cout << "Before: ";
	for (int x : m_sequence) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	std::cout << "After: ";
	for (int x : m_result) {
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

	return 0;
};

//Pairs code
      // if (!form_pairs)
        // {
            // Pair p;
            // p.a = first;
            // p.b = second;
            // pairs.push_back(p);
        // }
