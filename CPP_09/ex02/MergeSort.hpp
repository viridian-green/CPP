#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <deque>
#include <time.h>

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
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();

	int parseInput(int ac, char **arg);
    std::vector<int> getInput();
    int getNbrComparaisons();
    size_t maxFJComparisons(size_t n);
    void vec_duration();
    std::vector<Pair> make_pairs(std::vector<int> nums);
    std::vector<int> find_pend(std::vector<Pair> pairs);
    std::vector<int> find_main(std::vector<Pair> pairs);
     std::vector<int> jacobsthalOrder(size_t n) ;
    std::vector<int> FJAlgo(std::vector<int> input);
    std::vector<size_t> getOrder();
    std::vector<size_t> getJacobsthalOrder(size_t n);
    void printResult();

    private:
    std::vector<int> m_sequence;
	std::vector<int> m_result;
    int m_comparaisons = 0;
    int m_leftover = 0;
    std::vector<size_t> order;
    double dur_vec;

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