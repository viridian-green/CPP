#include "MergeSort.hpp"

	MergeSort::MergeSort() : m_leftover(-1) {}

	// MergeSort::MergeSort(const MergeSort &oth){}

	// MergeSort &MergeSort::operator=(const MergeSort &oth){}

	// MergeSort::~MergeSort(){}


//For debug purposes
std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << "(" << p.a << ", " << p.b << ")";
    return os;
}

void MergeSort::vectorAlgo()
{
	if (m_vec_sequ.size() == 1)
	{
		printResult(m_vec_sequ);
		return;
	}

	//Sort while creating initial pairs
	std::vector<Pair> pairs;
	for (size_t i = 0; i + 1 < m_vec_sequ.size(); i += 2) {
		if (m_vec_sequ[i] > m_vec_sequ[i + 1])
			pairs.push_back({m_vec_sequ[i], m_vec_sequ[i + 1]});
		else
			pairs.push_back({m_vec_sequ[i + 1], m_vec_sequ[i]});
	}

	//  for (Pair x : pairs) {
	// std::cout << x << " ";
	// }

	if (m_vec_sequ.size() % 2 == 1)
		m_has_leftover = 1;

	if (m_has_leftover)
		m_leftover = m_vec_sequ.back();
	else
		m_leftover = -1;

	std::vector<int> sorted = vecJohnsonSort(pairs, m_has_leftover, m_leftover);
}


void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}

// Compute a simple Jacobsthal-like order for n elements
std::vector<int> jacobsthalOrder(int n) {
    std::vector<int> order;
    if (n == 0) return order;
    int a = 1, b = 1;
    while (a < n) {
        order.push_back(a - 1);
        int tmp = a;
        a = b + 2 * a;
        b = tmp;
    }
    for (int i = 0; i < n; ++i)
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    return order;
}

void MergeSort::printResult(std::vector<int> v)
{
	std::cout << "Before: ";
	for (int x : m_vec_sequ) {
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

// Recursion
std::vector<int> MergeSort::vecJohnsonSort(std::vector<Pair>& pairs, bool hasLeftover, int leftoverValue) {

	// Base case
	if (pairs.size() == 1) {
		std::vector<int> base = {pairs[0].a, pairs[0].b};
		std::sort(base.begin(), base.end());
		if (hasLeftover)
			insertInSortedOrder(base, leftoverValue);
		printResult(base);
		return (base);
	}

    std::vector<Pair> nextLevelPairs;
    std::vector<int> pendings;

    // Step 1: pair up and split into bigger/smaller
    for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
        Pair bigger = pairs[i];
        Pair smaller = pairs[i + 1];

        if (smaller.a > bigger.a)
            std::swap(bigger, smaller);

        nextLevelPairs.push_back(bigger);
        pendings.push_back(smaller.a);
        pendings.push_back(smaller.b);
    }

    // Step 2: handle odd leftover pair at this level
    bool newHasLeftover = pairs.size() % 2 == 1;
    int newLeftover = newHasLeftover ? pairs.back().a : -1;

    // Step 3: recursively sort next level
    std::vector<int> sortedMains = vecJohnsonSort(nextLevelPairs, newHasLeftover, newLeftover);

    // Step 4: reorder this level according to sorted mains
    std::vector<Pair> orderedPairs;
    std::vector<bool> used(pairs.size(), false);

    for (int val : sortedMains) {
        for (size_t i = 0; i < pairs.size(); ++i) {
            if (!used[i] && pairs[i].a == val) {
                orderedPairs.push_back(pairs[i]);
                used[i] = true;
                break;
            }
        }
    }

    // Step 5: build final result
    std::vector<int> result;
    for (auto& p : orderedPairs)
        result.push_back(p.a);

    // Jacobsthal order insertions
    std::vector<int> order = jacobsthalOrder(orderedPairs.size());
    for (int idx : order) {
        if (idx < (int)orderedPairs.size())
            insertInSortedOrder(result, orderedPairs[idx].b);
    }

    // Insert all pendings
    for (int val : pendings)
        insertInSortedOrder(result, val);

    // Finally, insert leftover from upper level
    if (hasLeftover)
        insertInSortedOrder(result, leftoverValue);

	printResult(result);
    return (result);
}

int MergeSort::parseInput(int ac, char **arg) {
	//TODO: deal with eval input later
	for (int i = 1; i < ac; i++)
	{
		std::string token = arg[i];
		if (::isdigit(token[0]))
		{
			int value = std::stoi(token.c_str());
			if (std::find(m_vec_sequ.begin(), m_vec_sequ.end(), value) == m_vec_sequ.end()  && value >= 0)
			{
				m_vec_sequ.push_back(std::atoi(token.c_str()));
				m_deque_sequ.push_back(std::atoi(token.c_str()));
			}
		}
		else
			return 1;
	}
	return 0;

};
