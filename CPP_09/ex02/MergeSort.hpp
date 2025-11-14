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
    // Pair(int x, int y) : a(x), b(y) {}
};

class MergeSort{

	public:
	MergeSort();
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();
    // using value_type = typename Container::value_type;
    // using int_container  = Container<int>;
    // using pair_container = Container<Pair>;
	// void initContainers(const std::set<int>& input);
	int parseInput(int ac, char **arg);
	// void VecJohnsonFord();
	// void sort();
	// void FJalgo();
    // Container make_pairs(const std::vector<int>& input);
	// void printResult();
    // void mergeSort(Container& input, Container& main_chain,  Container& pend_chain);
    // void binarySearch();
	// Container getResult();
    std::vector<int> getInput();
	// int_container jacobsthalOrder(size_t n);
    std::vector<Pair> make_pairs(const std::vector<int>& nums);
    std::vector<int> find_pend(const std::vector<Pair>& pairs);
    std::vector<int> find_main(const std::vector<Pair>& pairs);
    std::vector<int> FJAlgo(const std::vector<int>& input);

    private:
    std::vector<int> m_sequence;
	std::vector<int> m_result;
    std::vector<Pair> pairs;
    int m_leftover;
    int form_pairs = -1;

};



// template <template <typename> class Container>
// int_container MergeSort<Container>::jacobsthalOrder(size_t n) {
//     int_container order;
//     if (n == 0)
//         return order;
//     int_container jacob;
//     jacob.push_back(0);
//     jacob.push_back(1);
//     while (jacob.back() < n - 1)
//         jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);

//     // The FJ algorithm uses Jacobsthal gaps to define insertion indices
//     size_t last = 1;
//     while (last < n) {
//         size_t next = jacob[last];
//         if (next > n - 1)
//             next = n - 1;
//         for (size_t i = next; i > jacob[last - 1]; --i)
//             order.push_back(i);
//         ++last;
//     }

//     return order;
// };

// template <template <typename> class Container>
// typename MergeSort<Container>::pair_container
// MergeSort<Container>::make_pairs(const typename MergeSort<Container>::int_container& input)
// {
//     pair_container pairs;
//     auto it = input.begin();

//     while (it != input.end()) {
//         int first = *it++;

//         if (it == input.end()) {
//             // Odd element → becomes a single pair with a dummy "−∞" or itself?
//             // For Ford-Johnson, we treat the last element as:
//             // a = element, b = element (self-pair)
//             pairs.push_back({first, first});
//             break;
//         }

//         int second = *it++;

//         if (first < second)
//             std::swap(first, second);

//         pairs.push_back({first, second});
//     }

//     return pairs;
// }



// template <typename Container>
// void MergeSort<Container>::printResult()
// {
//     if (m_result[0] == -1)
//         m_result = m_sequence;

// 	std::cout << "Before: ";
// 	for (int x : m_sequence) {
// 		std::cout << x << " ";
// 	}
// 	std::cout << "\n";

// 	std::cout << "After: ";
// 	for (int x : m_result) {
// 		std::cout << x << " ";
// 	}
// 	std::cout << "\n";

// 	//TODO: Implement the printing of the time
// }




// template <typename Container, typename T>
// typename Container::const_iterator binarySearch(const Container& container, const T& value)
// {
//     auto left = container.begin();
//     auto right = container.end();

//     while (left < right) {
//         // find the middle iterator
//         auto mid = left;
//         std::advance(mid, std::distance(left, right) / 2);

//         if (*mid == value)
//             return mid; // found
//         else if (*mid < value)
//             left = std::next(mid); // search right half
//         else
//             right = mid;           // search left half
//     }

//     return container.end(); // not found
// }