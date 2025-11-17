#include "MergeSort.hpp"


// MergeSort::MergeSort(const MergeSort &oth){}

// MergeSort &MergeSort::operator=(const MergeSort &oth){}

// MergeSort::~MergeSort(){}

#include <algorithm>
//For debug purposes
std::ostream& operator<<(std::ostream& os, const PairWithIndex& p) {
    os << "(" << p.bigger << ", " << p.smaller << ")";
    return os;
}

// Container MergeSort::getResult()
// {
// 	return m_result;
// }

std::vector<int> MergeSort::find_pend(std::vector<Pair> pairs)
{
    std::vector<int> pend_chain;
    pend_chain.reserve(pairs.size());

    for (const auto& p : pairs)
        pend_chain.push_back(p.b);

    return pend_chain;
}

std::vector<int> MergeSort::find_main(std::vector<Pair> pairs)
{
    std::vector<int> main_chain;
    main_chain.reserve(pairs.size());

    for (const auto& p : pairs)
        main_chain.push_back(p.a);

    return main_chain;
}
std::vector<size_t> generateJacobstahl(size_t n) {
    std::vector<size_t> jacobstahl;
    jacobstahl.push_back(0);
    if (n > 0) jacobstahl.push_back(1);

    size_t idx = 1;
    while (true) {
        size_t next = jacobstahl[idx] + 2 * jacobstahl[idx - 1];
        if (next >= n) break;
        jacobstahl.push_back(next);
        idx++;
    }

    return jacobstahl;
}

std::vector<size_t> getJacobsthalOrder(size_t n) {
    if (n == 0) return std::vector<size_t>();

    std::vector<size_t> jacobstahl = generateJacobstahl(n);
    std::vector<size_t> order;
    std::vector<bool> used(n, false);

    for (size_t i = 1; i < jacobstahl.size(); i++) {
        size_t jMax = jacobstahl[i];
        size_t jPrev = jacobstahl[i - 1];

        // Insert in descending order between jacobstahl numbers
        for (size_t j = jMax; j > jPrev && j <= n; j--) {
            if (j > 0 && !used[j - 1]) {
                order.push_back(j - 1);
                used[j - 1] = true;
            }
        }
    }

    // Add any remaining elements
    for (size_t i = 0; i < n; i++) {
        if (!used[i]) {
            order.push_back(i);
        }
    }

    return order;
}


//  std::vector<int> MergeSort::jacobsthalOrder(size_t n) {
//     std::vector<int>  order;
//     if (n == 0)
//         return order;
//     std::vector<int>  jacob;
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


 std::vector<int> MergeSort::FJAlgo(std::vector<int> input){

    if (input.size() <= 1) {
        return input;
    }

    std::vector<PairWithIndex> pairs;
    int straggler = -1;
    bool hasStraggler = false;


    // Create pairs and keep track of pairings
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        PairWithIndex p;
        int j = input[ i + 1];
        if (input[i] < input[i + 1]) {
            std::swap(input[i], input[i + 1]);
        }
        p.bigger = input[i];
        p.smaller = input[i + 1];
        p.originalIndex = pairs.size();
        pairs.push_back(p);
    }

    // Handle odd number of elements (straggler)
    if (input.size() % 2 == 1) {
        straggler = input[input.size() - 1];
        hasStraggler = true;
    }

    // Extract biggest elements for recursion
    std::vector<int> biggest;
    for (size_t i = 0; i < pairs.size(); i++) {
        biggest.push_back(pairs[i].bigger);
    }

    // Recursively sort the biggest vector
    biggest = FJAlgo(biggest);


    std::vector<PairWithIndex> sortedPairs;
    for (size_t i = 0; i < biggest.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].bigger == biggest[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs[j].bigger = -1; // Mark as used
                break;
            }
        }
    }

    // Start with sorted biggest vector
    std::vector<int> result = biggest;

    std::cout << "biggest: ";
	for (int x : biggest) {
		std::cout << x  << ".";
	}
    // Insert first smaller element at the beginning
    if (!sortedPairs.empty()) {
        result.insert(result.begin(), sortedPairs[0].smaller);
    }

    // Get Jacobstahl insertion order for remianing smaller elements
    std::vector<size_t> order = getJacobsthalOrder(sortedPairs.size());

    // Insert remaining smaller elements in Jacobstahl order
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0) continue; // Already inserted
        if (idx >= sortedPairs.size()) continue;


        int toInsert = sortedPairs[idx].smaller;
        int pairBigger = sortedPairs[idx].bigger;

        // Find position of the paired bigger element
        std::vector<int>::iterator pairPos = std::find(result.begin(), result.end(), pairBigger);

        // Binary search up to the paired element's position using lower_bound
        std::vector<int>::iterator insertPos = std::lower_bound(result.begin(), pairPos + 1, toInsert);
        result.insert(insertPos, toInsert);
    }

    // Insert straggler if exists
    if (hasStraggler) {
        size_t pos = 0;
        while (pos < result.size() && result[pos] < straggler) {
            pos++;
        }
        result.insert(result.begin() + pos, straggler);
    }



    std::cout << "result: ";
	for (int x : result) {
		std::cout << x  << ".";
	}

    return result;
}

//  std::vector<int> MergeSort::FJAlgo(const std::vector<int>& input){
//     if (input.size() <= 1) {
//         return input;
//     }

//     std::vector<int> smallest;
//     std::vector<int> biggest;
//     int straggler = -1;
//     bool hasStraggler = false;

//     // Create pairs and separate into smallest and biggest
//     for (size_t i = 0; i + 1 < input.size(); i += 2) {
//         Pair p;
//         p.a = input[i];
//         p.b = input[i + 1];

//         if (p.a > p.b) {
//             biggest.push_back(p.a);
//             smallest.push_back(p.b);
//         } else {
//             biggest.push_back(p.b);
//             smallest.push_back(p.a);
//         }
//     }

//     // Handle odd number of elements (straggler)
//     if (input.size() % 2 == 1) {
//         straggler = input[input.size() - 1];
//         hasStraggler = true;
//     }

//     // Recursively sort the biggest vector
//     biggest = FJAlgo(biggest);

//     // Start with sorted biggest vector
//     std::vector<int> result = biggest;

//     // Insert first element of smallest (it's always smaller than first of biggest)
//     if (!smallest.empty()) {
//         result.insert(result.begin(), smallest[0]);
//     }

//     // Get Jacobstahl insertion order for remaining elements
//     std::vector<int> order = jacobsthalOrder(smallest.size());

//     // Insert remaining smallest elements in Jacobstahl order
//     for (size_t i = 0; i < order.size(); i++) {
//         size_t idx = order[i];
//         if (idx == 0) continue; // Already inserted
//         if (idx >= smallest.size()) continue;

//         int toInsert = smallest[idx];

//         // Binary search for insertion position
//         size_t left = 0;
//         size_t right = result.size();
//         while (left < right) {
//             size_t mid = left + (right - left) / 2;
//             if (result[mid] < toInsert) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         result.insert(result.begin() + left, toInsert);
//     }

//     // Insert straggler if exists
//     if (hasStraggler) {
//         size_t pos = 0;
//         while (pos < result.size() && result[pos] < straggler) {
//             pos++;
//         }
//         result.insert(result.begin() + pos, straggler);
//     }


//     std::cout << "Sorted_main: ";
// 	for (int x : result) {
// 		std::cout << x << ".";
// 	}

//     return result;
// }

//     return result;  // Return result, not just smallest!
// }

// std::vector<int> MergeSort::FJAlgo(const std::vector<int>& input)
// {
//     // Base case
//     if (input.size() <= 1)
//         return input;

//     // Step 1: make pairs
//     std::vector<Pair> pairs = make_pairs(input);

//     for (Pair x : pairs) {
// 		std::cout << x << ".";
//     }
//     // Step 2: split main (larger) and pend (smaller)
//     std::vector<int> main_chain = find_main(pairs);  // a_i
//     std::vector<int> pend_chain = find_pend(pairs);  // b_i

//     // Step 3: recursively sort the main chain
//     std::vector<int> sorted_main = FJAlgo(main_chain);


//     // std::cout << "Sorted_main: ";
// 	// for (int x : sorted_main) {
// 	// 	std::cout << x << ".";
// 	// }

//     // Insert pend elements **now, before returning**
// std::vector<int> order = jacobsthalOrder(pend_chain.size());
// for (size_t idx : order) {
//     int val = pend_chain[idx];

//     // Insert relative to the main element in sorted_main
//     // **Use the index in sorted_main that matches a_i**, NOT the original pairs[idx].a
//     auto partner_it = std::find(sorted_main.begin(), sorted_main.end(), main_chain[idx]);
//     if (partner_it == sorted_main.end()) partner_it = sorted_main.end();

//     sorted_main.insert(partner_it, val);
// }

//     std::cout << "Sorted_main: ";
// 	for (int x : sorted_main) {
// 		std::cout << x << ".";
// 	}
// 	std::cout << "\n";

// return sorted_main;



//     return sorted_main;
// }

std::vector<int> MergeSort::getInput()
{
	return m_sequence;
}

int MergeSort::parseInput(int ac, char **arg) {

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

MergeSort::MergeSort() {}

std::vector<Pair> MergeSort::make_pairs(std::vector<int> nums)
{
    std::vector<Pair> pairs;
    auto it = nums.begin();

    if (nums.size() % 2 == 1) {
    m_leftover = nums.back();  // Get the last element's value
}

    while (it != nums.end()) {
        int x = *it++;

        if (it == nums.end()) {
            break;
        }

        int y = *it++;
        if (x > y) std::swap(x, y);

        pairs.push_back({x, y});
    }

    return pairs;
}

void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}





