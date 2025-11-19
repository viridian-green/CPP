#include "MergeSort.hpp"


// MergeSort::MergeSort(const MergeSort &oth){}

// MergeSort &MergeSort::operator=(const MergeSort &oth){}

// MergeSort::~MergeSort(){}

//For debug purposes
std::ostream& operator<<(std::ostream& os, const PairWithIndex& p) {
    os << "(" << p.main << ", " << p.pend << ")";
    return os;
}

int MergeSort::getNbrComparaisons()
{
    return m_comparaisons;
}

// Container MergeSort::getResult()
// {
// 	return m_result;
// }

void MergeSort::printResult()
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



std::vector<size_t> generateJacobstahl(size_t n) {
    std::vector<size_t> jacobstahl;
    jacobstahl.push_back(0);
    if (n > 0) 
        jacobstahl.push_back(1);

    size_t idx = 1;
    while (true) {
        size_t next = jacobstahl[idx] + 2 * jacobstahl[idx - 1];
        if (next >= n) 
            break;
        jacobstahl.push_back(next);
        idx++;
    }

    return jacobstahl;
}

std::vector<size_t> MergeSort::getJacobsthalOrder(size_t n) {
    if (n == 0) 
        return std::vector<size_t>();

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
            m_comparaisons++;
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
                m_comparaisons++;
                sortedPairs.push_back(pairs[j]);
                pairs[j].main = -1;
                break;
            }
        }
    }

    // Start with sorted biggest vector
    std::vector<int> result = main_chain;

    // Insert first smaller element at the beginning
    if (!sortedPairs.empty()) {
        result.insert(result.begin(), sortedPairs[0].pend);
    }

    // Get Jacobstahl insertion order for remianing smaller elements
    std::vector<size_t> order = getJacobsthalOrder(sortedPairs.size());

    // Insert remaining smaller elements in Jacobstahl order
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        	std::cout << order[i] << ".";
        if (idx == 0) 
            continue;
        if (idx >= sortedPairs.size()) 
            continue;

        int toInsert = sortedPairs[idx].pend;
        int pairBigger = sortedPairs[idx].main;

        //Max pos is the pend's pair 
        size_t maxPos = 0;
        for (size_t j = 0; j < result.size(); j++) {
            if (result[j] == pairBigger) {
                maxPos = j;
                break;
            }
        }

        // Binary search up to the paired element's position
        size_t left = 0;
        size_t right = maxPos + 1;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < toInsert) {
                m_comparaisons++;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        result.insert(result.begin() + left, toInsert);
    }

    // Insert straggler without jacobstahl order 
    if (has_leftover) {
        size_t pos = 0;
        while (pos < result.size() && result[pos] < leftover) {
            m_comparaisons++;
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

void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}





