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

std::vector<int> MergeSort::getResult()
{
	return m_result;
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
};

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


void MergeSort::vectorAlgo()
{
	if (m_vec_sequ.size() == 1)
	{
		printResult(m_vec_sequ);
		return;
	}

	//Step 1 + 2 : Sort while creating initial pairs
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

	std::vector<int> sorted = vecJohnsonSort(m_vec_sequ, m_has_leftover, m_leftover);
}

// Recursion
std::vector<int> MergeSort::vecJohnsonSort(std::vector<int>& mains, bool hasLeftover, int leftoverValue) {

	// Base case
	if (mains.size() == 1) {
		std::vector<int> base = mains;
        if (hasLeftover)
            insertInSortedOrder(base, leftoverValue);
        return base;
		return (base);
	}

	std::vector<int> nextLevel; //main chain
	std::vector<int> pendings; //pend chain: vector of individual numbers

	//These pairs are already sorted, with .a being the bigger element and .b the smaller
	// Step 3: Compare .a and .a + 1, swap and send lower number to pend chain
	 for (size_t i = 0; i + 1 < mains.size(); i += 2) {
        int left = mains[i];
        int right = mains[i + 1];
        if (right > left) std::swap(left, right);
        nextLevel.push_back(left);
        pendings.push_back(right);
    }

    bool newLeftover = mains.size() % 2 == 1;
    int newLeftoverValue = newLeftover ? mains.back() : -1;

    std::vector<int> sortedMains = vecJohnsonSort(nextLevel, newLeftover, newLeftoverValue);


	for (int x : sortedMains) {
		std::cout << x << " ";
	}std::cout << "\n";

		for (int x : pendings) {
		std::cout << x << "->> ";
	}std::cout << "\n";

    // // Step 6: reorder this level according to sorted mains
    // std::vector<Pair> orderedPairs;
    // std::vector<bool> used(mains.size(), false);

//     for (int val : sortedMains) {
//         for (size_t i = 0; i < mains.size(); ++i) {
//             if (!used[i] && mains[i].a == val) {
//                 orderedPairs.push_back(mains[i]);
//                 used[i] = true;
//                 break;
//             }
//         }
//     }

//     // Step 5: build final result
//     std::vector<int> result;
//     for (auto& p : orderedPairs)
//         result.push_back(p.a);

//     // Jacobsthal order insertions
//     std::vector<int> order = jacobsthalOrder(orderedPairs.size());
//     for (int idx : order) {
//         if (idx < (int)orderedPairs.size())
//             insertInSortedOrder(result, orderedPairs[idx].b);
//     }

//     // Insert all pendings
//     for (int val : pendings)
//         insertInSortedOrder(result, val);

//     // Finally, insert the leftover from original input
//     if (hasLeftover)
//         insertInSortedOrder(result, leftoverValue);

// 	// printResult(result);
// 	m_result = result;
    return (sortedMains);
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

// 	for (int idx : jacobsthalOrder(orderedPairs.size())) {
//     int b = orderedPairs[idx].b;
//     int a = orderedPairs[idx].a;

//     // find position of 'a' in result
//     auto a_pos = std::find(result.begin(), result.end(), a);

//     // insert 'b' only up to a_pos
//     auto pos = std::lower_bound(result.begin(), a_pos, b);
//     result.insert(pos, b);
// }
