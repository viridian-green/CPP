#include "MergeSort.hpp"


// MergeSort::MergeSort(const MergeSort &oth){}

// MergeSort &MergeSort::operator=(const MergeSort &oth){}

// MergeSort::~MergeSort(){}

//For debug purposes
std::ostream& operator<<(std::ostream& os, const PairWithIndex& p) {
    os << "(" << p.main << ", " << p.pend << ")";
    return os;
}



// std::vector<size_t> MergeSort::getJacobsthalOrder(size_t n){
// 	std::vector<size_t> jacobsthal;
// 	size_t j0 = 0, j1 = 1;
// 	while (true) {
// 		size_t next = j1 + 2 * j0;
// 		if (next >= n)
// 			break;
// 		jacobsthal.push_back(next);
// 		j0 = j1;
// 		j1 = next;
// 	}
// 	std::vector<size_t> order;
// 	if (n == 0)
// 		return order;
// 	order.push_back(0);
// 	for (size_t i = 0; i < jacobsthal.size(); ++i) {
// 		size_t current = jacobsthal[i];
// 		size_t previous = (i == 0) ? 0 : jacobsthal[i-1];
		
// 		if (current < n) {
// 			order.push_back(current);
// 		}
		
// 		for (size_t j = current - 1; j > previous; --j) {
// 			if (j < n) {
// 				order.push_back(j);
// 			}
// 		}
// 	}
	
// 	for (size_t i = 0; i < n; ++i) {
// 		if (std::find(order.begin(), order.end(), i) == order.end()) {
// 			order.push_back(i);
// 		}
// 	}
// 	return order;
// }

// std::vector<size_t> MergeSort::getJacobsthalOrder(size_t n) {
//     if (n == 0) 
//         return std::vector<size_t>();

//     std::vector<size_t> jacobstahl = generateJacobstahl(n);
//     std::vector<size_t> order;
//     std::vector<bool> used(n, false);

//     for (size_t i = 1; i < jacobstahl.size(); i++) {
//         size_t jCurrent = jacobstahl[i];
//         size_t jPrev = jacobstahl[i - 1];

//         Cap jCurrent at n (don't go beyond our array size)
//         size_t insertUpTo = std::min(jCurrent, n);

//         Insert in DESCENDING order from insertUpTo down to jPrev+1
//         for (size_t j = insertUpTo; j > jPrev; j--) {
//             if (j > 0 && !used[j - 1]) {  // j is 1-indexed, convert to 0-indexed
//                 order.push_back(j - 1);
//                 used[j - 1] = true;
//             }
//         }
//     }

//     Add any remaining elements in order
//     for (size_t i = 0; i < n; i++) {
//         if (!used[i]) {
//             order.push_back(i);
//         }
//     }

//     return order;
// }
// std::vector<size_t> MergeSort::getJacobsthalOrder(size_t n) {
//     if (n == 0) 
//         return std::vector<size_t>();

//     std::vector<size_t> jacobstahl = generateJacobstahl(n);
//     std::vector<size_t> order;
//     std::vector<bool> used(n, false);

//     for (size_t i = 1; i < jacobstahl.size(); i++) {
//         size_t jCurrent = jacobstahl[i];
//         size_t jPrev = jacobstahl[i - 1];

//         // Insert in DESCENDING order from jCurrent down to jPrev+1
//         for (size_t j = jCurrent; j > jPrev; j--) {
//             if (j <= n && j > 0) {  // j is 1-indexed, convert to 0-indexed
//                 order.push_back(j - 1);
//                 used[j - 1] = true;
//             }
//         }
//     }

//     // Add any remaining elements in order
//     for (size_t i = 0; i < n; i++) {
//         if (!used[i]) {
//             order.push_back(i);
//         }
//     }

//     return order;
// }

int MergeSort::getNbrComparaisons()
{
    return m_comparaisons;
}

void MergeSort::printResult()
{
    if (m_result[0] == -1)
        m_result = m_sequence;

	std::cout << "Before:  ";
	for (int x : m_sequence) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	std::cout << "After:  ";
	for (int x : m_result) {
		std::cout << x << " ";
	}
	std::cout << "\n";

    std::cout << "Time to process a range  of " << m_sequence.size() << " elements with std::vector : ";
    std::printf("%.6fs", dur_vec);
    std::cout << "Time to process a range  of " << m_sequence.size() << " elements with std::deque : " << std::endl;
	
    std::cout << "Comparaisons used :" << getNbrComparaisons() << std::endl;

}

// std::vector<size_t> generateJacobstahl(size_t n) {
//     std::vector<size_t> jacobstahl;
//     jacobstahl.push_back(0);
//     if (n > 0) 
//         jacobstahl.push_back(1);

//     size_t idx = 1;
//     while (true) {
//         size_t next = jacobstahl[idx] + 2 * jacobstahl[idx - 1];
//         if (next >= n) 
//             break;
//         jacobstahl.push_back(next);
//         idx++;
//     }

//     return jacobstahl;
// }

void MergeSort::vec_duration()
{
    clock_t start = clock();
    clock_t end = clock();
    dur_vec = double(end - start) / CLOCKS_PER_SEC;
}

// std::vector<size_t> MergeSort::getJacobsthalOrder(size_t n) {
//     if (n == 0) 
//         return std::vector<size_t>();

//     std::vector<size_t> jacobstahl = generateJacobstahl(n);
//     std::vector<size_t> order;
//     std::vector<bool> used(n, false);

//     for (size_t i = 1; i < jacobstahl.size(); i++) {
//         size_t jMax = jacobstahl[i];
//         size_t jPrev = jacobstahl[i - 1];

//         // Insert in descending order between jacobstahl numbers
//         for (size_t j = jMax; j > jPrev && j <= n; j--) {
//             if (j > 0 && !used[j - 1]) {
//                 order.push_back(j - 1);
//                 used[j - 1] = true;
//             }
//         }
//     }

//     // Add any remaining elements
//     for (size_t i = 0; i < n; i++) {
//         if (!used[i]) {
//             order.push_back(i);
//         }
//     }

//     return order;
// }

int jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<size_t> generateJacobstahl(size_t n)
{
    std::vector<size_t> sequence;
    int i = 1;
    int lastValue = -1;
    while (sequence.size() < n) {
        int jn = jacobsthal(i);
        if (jn > (int)n) {
            break;
        }
        if (jn != 0 && jn != lastValue) {
            sequence.push_back(jn);
            lastValue = jn;
        }
        i++;
    }
    //Fill in remaining indices after last Jacobstahl number
    if (!sequence.empty() && sequence.back() < (int)n) {
        for (int j = sequence.back() + 1; j <= (int)n; j++) {
            sequence.push_back(j);
        }
    }
    return sequence;
}

std::vector<size_t> MergeSort::getJacobsthalOrder(size_t n) {
    if (n == 0) 
        return std::vector<size_t>();

    std::vector<size_t> jacobstahl = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
    // std::vector<size_t> jacobstahl = generateJacobstahl(n);
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
    m_result = main_chain;

    // Insert first smaller element at the beginning
    if (!sortedPairs.empty()) {
        m_result.insert(m_result.begin(), sortedPairs[0].pend);
    }

    // Get Jacobstahl insertion order for remianing smaller elements
   order = getJacobsthalOrder(sortedPairs.size());

    // Insert remaining smaller elements in Jacobstahl order
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0) 
            continue;
        if (idx >= sortedPairs.size()) 
            continue;

        int toInsert = sortedPairs[idx].pend;
        int pairBigger = sortedPairs[idx].main;

        //Max pos is the pend's pair 
        size_t maxPos = 0;
        for (size_t j = 0; j < m_result.size(); j++) {
            if (m_result[j] == pairBigger) {
                maxPos = j;
                break;
            }
        }

        // Binary search up to the paired element's position
        size_t left = 0;
        size_t right = maxPos + 1;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (m_result[mid] < toInsert) {
                m_comparaisons++;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        m_result.insert(m_result.begin() + left, toInsert);
    }

    // Insert straggler without jacobstahl order 
    if (has_leftover) {
        size_t pos = 0;
        while (pos < m_result.size() && m_result[pos] < leftover) {
            m_comparaisons++;
            pos++;
        }
        m_result.insert(m_result.begin() + pos, leftover);
    }

    return m_result;
}


std::vector<int> MergeSort::getInput()
{
	return m_sequence;
}

std::vector<size_t> MergeSort::getOrder()
{
	return order;
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





