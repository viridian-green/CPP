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
void MergeSort::makePairs(const std::vector<int>& sequence, std::vector<int>& main_chain, std::vector<int>& pend_chain) {

    if (sequence.size() == 2)
        return;

    // Step 1 + 2: Sort while creating initial pairs
	// Step 3: Compare numbers and send lower number to pend chain, bigger to main chain
    for (size_t i = 0; i + 1 < sequence.size(); i += 2) {
        if (sequence[i] > sequence[i + 1])
		{
            main_chain.push_back(sequence[i]);
			pend_chain.push_back(sequence[i + 1]);
		}
        else
        {
			main_chain.push_back(sequence[i + 1]);
			pend_chain.push_back(sequence[i]);
		}
    }

	// Handle leftover if the sequence has odd size
    // if (sequence.size() % 2 == 1)
    //     m_has_leftover = 1;
    // else
    //     m_has_leftover = 0;

    // if (m_has_leftover)
    //     m_leftover = sequence.back();
    // else
    //     m_leftover = -1;

}

void MergeSort::vectorAlgo() {
    if (m_vec_sequ.size() == 1) {
        printResult(m_vec_sequ);
        return;
    }

    // for (int x : m_vec_sequ) {
    //     std::cout << x << " ";
    // } std::cout << "\n";

    // Perform Ford–Johnson style sort
    vecJohnsonSort(m_vec_sequ, m_has_leftover, m_leftover);
}


// Recursion
std::vector<int> MergeSort::vecJohnsonSort(std::vector<int> input, bool hasLeftover, int leftoverValue) {

    if (input.size() <= 2)
        return input;

    // Base case

    std::vector<int> main_chain;
    std::vector<int> pend_chain;

    makePairs(input, main_chain, pend_chain);

	// for (int x : input) {
    //     std::cout << x << " ";
    // } std::cout << "\n";
    // Step 5: recursively sort next level
    std::vector<int> sorted_main = vecJohnsonSort(main_chain, m_has_newleftover, m_newleftover);

	 for (int x : main_chain) {
        std::cout << x << ". ";
    } std::cout << "\n";

    	 for (int x : pend_chain) {
        std::cout << x << "< ";
    } std::cout << "\n";

	return (sorted_main);
    // Step 6: reorder this level according to sorted mains
    // std::vector<Pair> orderedPairs;
    // std::vector<bool> used(pairs.size(), false);
    // for (int val : sortedMains) {
    //     for (size_t i = 0; i < pairs.size(); ++i) {
    //         if (!used[i] && pairs[i].a == val) {
    //             orderedPairs.push_back(pairs[i]);
    //             used[i] = true;
    //             break;
    //         }
    //     }
    // }

    // // Step 7: build final result
    // std::vector<int> result;
    // for (auto& p : orderedPairs)
    //     result.push_back(p.a);

    // // Jacobsthal order insertions
    // std::vector<int> order = jacobsthalOrder(orderedPairs.size());
    // for (int idx : order) {
    //     if (idx < (int)orderedPairs.size())
    //         insertInSortedOrder(result, orderedPairs[idx].b);
    // }

    // // Insert all pendings
    // for (int val : pend_chain)
    //     insertInSortedOrder(result, val);

    // // Finally, insert the leftover from original input
    // if (hasLeftover)
    //     insertInSortedOrder(result, leftoverValue);

    // // printResult(result);
    // m_result = result;
    // return result;
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
