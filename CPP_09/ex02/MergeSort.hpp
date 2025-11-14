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

template <template <typename> class Container>
class MergeSort{

	public:
	MergeSort();
	// MergeSort(const MergeSort &oth);
	// MergeSort &operator=(const MergeSort &oth);
	// ~MergeSort();
    using value_type = typename Container::value_type;
    using int_container  = Container<int>;
    using pair_container = Container<Pair>;
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
    // Container getInput();
	int_container jacobsthalOrder(size_t n);
    pair_container make_pairs(const Container& input);
    // Container find_pend(const std::vector<Pair>& pairs);
    // Container find_main(const std::vector<Pair>& pairs);

    private:
    int_container m_sequence;
	int_container m_result;
    pair_container pairs;
    int form_pairs = -1;

};

template <template <typename> class Container>
MergeSort<Container>::MergeSort() {}

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
// Container MergeSort<Container>::find_pend(const std::vector<Pair>& pairs)
// {
//     std::vector<int> pend_chain;
//     pend_chain.reserve(pairs.size());

//     for (const auto& p : pairs)
//         pend_chain.push_back(p.b);

//     return pend_chain;
// }
// template <typename Container>
// Container MergeSort<Container>::find_main(const std::vector<Pair>& pairs)
// {
//     std::vector<int> main_chain;
//     main_chain.reserve(pairs.size());

//     for (const auto& p : pairs)
//         main_chain.push_back(p.a);

//     return main_chain;
// }

std::vector<Pair> make_pairs(const std::vector<int>& nums)
{
    std::vector<Pair> pairs;
    auto it = nums.begin();

    while (it != nums.end()) {
        int x = *it++;

        if (it == nums.end()) {
            // odd → self-pair
            pairs.push_back({x, x});
            break;
        }

        int y = *it++;
        if (x < y) std::swap(x, y);

        pairs.push_back({x, y});
    }

    return pairs;
}


// std::vector<Pair> JAlgo(const std::vector<Pair>& pairs)
// {
//     // base case
//     if (pairs.size() <= 1)
//         return pairs;

//     // extract main and pend values
//     std::vector<int> main_chain = find_main(pairs);
//     std::vector<int> pend_chain = find_pend(pairs);

//     // recursively pair and sort the pend chain
//     std::vector<Pair> main_pairs = make_pairs(main_chain);
//     std::vector<Pair> sorted_pend = JAlgo(main_pairs);

//     // now reorder original pairs according to sorted pend values
//     std::vector<Pair> out;
//     out.reserve(pairs.size());

//     for (const auto& sp : sorted_pend) {
//         for (const auto& orig : pairs) {
//             if (sp.b == orig.b) {
//                 out.push_back(orig);
//                 break;
//             }
//         }
//     }

//     return out;
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

template <template <typename> class Container>
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