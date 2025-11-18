#include "MergeSort.hpp"


// MergeSort::MergeSort(const MergeSort &oth){}

// MergeSort &MergeSort::operator=(const MergeSort &oth){}

// MergeSort::~MergeSort(){}

#include <algorithm>
//For debug purposes
std::ostream& operator<<(std::ostream& os, const PairWithIndex& p) {
    os << "(" << p.main << ", " << p.pend << ")";
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

 std::vector<int> MergeSort::FJAlgo(std::vector<int> input){

    if (input.size() <= 1) {
        return input;
    }

    std::vector<PairWithIndex> pairs;
    int leftover = -1;
    bool has_leftover = false;

    //
    std::vector<int> main_chain;

//Keep track of original pairing when building the pairs
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        PairWithIndex p;
        if (input[i] < input[i + 1]) {
            std::swap(input[i], input[i + 1]);
        }
        p.main = input[i];
        p.pend = input[i + 1];
        main_chain.push_back(input[i]);
        p.originalIndex = pairs.size();
        pairs.push_back(p);
    }

    // Handle odd number of elements (straggler)
    if (input.size() % 2 == 1) {
        leftover = input.back();
        has_leftover = true;
    }

    // Recursively sort the main chain
    main_chain = FJAlgo(main_chain);

    std::vector<PairWithIndex> sortedPairs;
    for (size_t i = 0; i < main_chain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].main == main_chain[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs[j].main = -1; // Mark as used
                break;
            }
        }
    }

    // Start with sorted biggest vector
    std::vector<int> result = main_chain;

    std::cout << "biggest: ";
	for (int x : main_chain) {
		std::cout << x  << ".";
	}
    // Insert first smaller element at the beginning
    if (!sortedPairs.empty()) {
        result.insert(result.begin(), sortedPairs[0].pend);
    }

    // Get Jacobstahl insertion order for remianing smaller elements
    std::vector<size_t> order = getJacobsthalOrder(sortedPairs.size());

    // Insert remaining smaller elements in Jacobstahl order
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0) continue; // Already inserted
        if (idx >= sortedPairs.size()) continue;


        int toInsert = sortedPairs[idx].pend;
        int pairBigger = sortedPairs[idx].main;

        // Find position of the paired bigger element
        std::vector<int>::iterator pairPos = std::find(result.begin(), result.end(), pairBigger);

        // Binary search up to the paired element's position using lower_bound
        std::vector<int>::iterator insertPos = std::lower_bound(result.begin(), pairPos + 1, toInsert);
        result.insert(insertPos, toInsert);
    }

    // Insert straggler if exists
    if (has_leftover) {
        size_t pos = 0;
        while (pos < result.size() && result[pos] < leftover) {
            pos++;
        }
        result.insert(result.begin() + pos, leftover);
    }

    std::cout << "result: ";
	for (int x : result) {
		std::cout << x  << ".";
	}

    return result;
}


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





