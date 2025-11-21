#include "MergeSort.hpp"


MergeSort::MergeSort()
: vec_sequence(),
  vec_result(),
  deq_sequence(),
  d_result(),
  m_comparaisons(0),
  m_leftover(0),
  order(),
  d_order(),
  dur_vec(0),
  dur_deq(0)
{}


MergeSort::MergeSort(const MergeSort &oth)
: vec_sequence(oth.vec_sequence),
  vec_result(oth.vec_result),
  deq_sequence(oth.deq_sequence),
  d_result(oth.d_result),
  m_comparaisons(oth.m_comparaisons),
  m_leftover(oth.m_leftover),
  order(oth.order),
  d_order(oth.d_order),
  dur_vec(oth.dur_vec),
  dur_deq(oth.dur_deq)
{}

MergeSort &MergeSort::operator=(const MergeSort &oth) {
    if (this != &oth) {
        vec_sequence = oth.vec_sequence;
        vec_result = oth.vec_result;
        deq_sequence = oth.deq_sequence;
        d_result = oth.d_result;

        m_comparaisons = oth.m_comparaisons;
        m_leftover = oth.m_leftover;

        order = oth.order;
        d_order = oth.d_order;

        dur_vec = oth.dur_vec;
        dur_deq = oth.dur_deq;
    }
    return *this;
}


MergeSort::~MergeSort() {}

//For debug purposes
std::ostream& operator<<(std::ostream& os, const PairWithIndex& p) {
    os << "(" << p.main << ", " << p.pend << ")";
    return os;
}


std::vector<int> MergeSort::getInput()
{
	return vec_sequence;
}

std::vector<size_t> MergeSort::getOrder()
{
	return order;
}


int MergeSort::getNbrComparaisons()
{
    return m_comparaisons;
}


void MergeSort::setDurVec(double input)
{
    dur_vec = input;
}
void MergeSort::setDurDeq(double input)
{
    dur_deq = input;
}


//Code for vector
void MergeSort::printResultV()
{
    if (vec_result.empty() || (vec_result.size() > 0 && *vec_result.begin() == -1))
        vec_result = vec_sequence;

	std::cout << "Before:  ";
	for (int x : vec_sequence) {
		std::cout << x << " ";
	}
	std::cout << "\n";

    if (std::is_sorted(vec_result.begin(), vec_result.end()) && vec_result.size() == vec_sequence.size())
        std::cout << "After:  ";
    else
        std::cout << "Output is incorrect!";
    for (int x : vec_result) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Time to process a range of " << vec_result.size() << " elements: with std::vector : ";
    std::printf("%.6fs\n", dur_vec);

    std::cout << "Comparisons used: " << getNbrComparaisons() << std::endl;

    std::cout << "order: ";
    for (size_t x : getOrder()) {
    	std::cout << x + 1 << " ";
    }
    std::cout << "\n";

}

void MergeSort::printResultD()
{
    if (d_result.empty() || (d_result.size() > 0 && *d_result.begin() == -1))
        d_result = deq_sequence;

	std::cout << "Before:  ";
	for (int x : deq_sequence) {
		std::cout << x << " ";
	}
	std::cout << "\n";

	std::cout << "After:  ";
	for (int x : d_result) {
		std::cout << x << " ";
	}
	std::cout << "\n";

    std::cout << "Time to process a range of " << d_result.size() << " elements: with std::deque : ";
    std::printf("%.6fs\n", dur_deq);

    std::cout << "Comparisons used: " << getNbrComparaisons() << std::endl;

    // std::cout << "order: ";
    // for (size_t x : getOrder()) {
    // 	std::cout << x + 1 << " ";
    // }
    std::cout << "\n";

}

int MergeSort::parseInputV(int ac, char **arg) {

    for (int i = 1; i < ac; i++) {

        std::string token = arg[i];
        if (::isdigit(token[0])) {

            int value = std::stoi(token.c_str());
            if (std::find(vec_sequence.begin(), vec_sequence.end(), value) == vec_sequence.end() && value >= 0) {

                vec_sequence.push_back(value);
                deq_sequence.push_back(value);
            }
        } else
            return 1;
    }
    return 0;
}

    std::vector<size_t> MergeSort::generateJacobstahl(size_t n) {
    std::vector<size_t> jacobstahl;
    jacobstahl.push_back(0);
    if (n > 0)
        jacobstahl.push_back(1);

    size_t idx = 1;
    while (true) {
        size_t next = jacobstahl[idx] + 2 * jacobstahl[idx - 1];
        jacobstahl.push_back(next);
        if (next >= n)
            break;
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

        size_t jCurrent = jacobstahl[i];
        size_t jPrev = jacobstahl[i - 1];

        size_t insertUpTo = std::min(jCurrent, n);

        for (size_t j = insertUpTo; j > jPrev; j--) {
            if (j > 0 && !used[j - 1]) {
                order.push_back(j - 1);
                used[j - 1] = true;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (!used[i]) {
            order.push_back(i);
        }
    }

    return order;
}

std::vector<int> MergeSort::FJAlgoVec(std::vector<int> input){
    if (input.size() <= 1) {
        return input;
    }

    std::vector<PairWithIndex> pairs;
    int  leftover = -1;
    bool has_leftover = false;

    std::vector<int> main_chain;
    std::vector<int> pend_chain;

    auto it = input.begin();
    while (it != input.end()) {
        auto first = it++;
        if (it == input.end()) {
            leftover = *first;
            has_leftover = true;
            break;
        }
        auto second = it++;

        PairWithIndex p;
        if (*first < *second) {
            std::swap(*first, *second);
        }
        p.main = *first;
        p.pend = *second;
        main_chain.push_back(*first);
        pend_chain.push_back(*second);
        p.originalIndex = pairs.size();
        pairs.push_back(p);
    }std::cout << "\n=== BEFORE RECURSION ===" << std::endl;
    std::cout << "Main chain: ";
    for (auto val : main_chain) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "Pend chain: ";
    for (auto val : pend_chain) std::cout << val << " ";
    std::cout << std::endl;

    main_chain = FJAlgoVec(main_chain);

    std::cout << "\n=== AFTER RECURSION ===" << std::endl;
    std::cout << "Sorted main chain: ";
    for (auto val : main_chain) std::cout << val << " ";
    std::cout << std::endl;

    vec_result = main_chain;

    std::cout << "\n=== INSERTION PROCESS ===" << std::endl;
    std::cout << "Initial result (main chain): ";
    for (auto val : vec_result) std::cout << val << " ";
    std::cout << std::endl;

    if (!pairs.empty()) {
        vec_result.insert(vec_result.begin(), pairs[0].pend);
        std::cout << "Inserted first pend element (" << pairs[0].pend << ") at front: ";
        for (auto val : vec_result) std::cout << val << " ";
        std::cout << std::endl;
    }

    order = getJacobsthalOrder(pend_chain.size());

    std::cout << "\nJacobsthal order: ";
    for (auto idx : order) std::cout << idx + 1 << " ";
    std::cout << std::endl << std::endl;

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0)
            continue;
        if (idx >= pairs.size())
            continue;

        int toInsert = pairs[idx].pend;
        int pairBigger = pairs[idx].main;

        std::cout << "--- Step " << i << " ---" << std::endl;
        std::cout << "Inserting pend[" << idx + 1 << "] = " << toInsert
                  << " (paired with main = " << pairBigger << ")" << std::endl;

        size_t maxPos = 0;
        for (size_t j = 0; j < vec_result.size(); j++) {
            if (vec_result[j] == pairBigger) {
                maxPos = j;
                break;
            }
        }
        std::cout << "Search range: [0, " << maxPos << "]" << std::endl;

        size_t left = 0;
        size_t right = maxPos + 1;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            auto mid_it = vec_result.begin();
            std::advance(mid_it, mid);
            m_comparaisons++;
            std::cout << "  Binary search: mid=" << mid << ", value=" << *mid_it;
            if (*mid_it < toInsert) {
                std::cout << " < " << toInsert << " -> search right" << std::endl;
                left = mid + 1;
            } else {
                std::cout << " >= " << toInsert << " -> search left" << std::endl;
                right = mid;
            }
        }

        vec_result.insert(vec_result.begin() + left, toInsert);
        std::cout << "Inserted at position " << left << ": ";
        for (auto val : vec_result) std::cout << val << " ";
        std::cout << std::endl << std::endl;
    }

    if (has_leftover) {
        std::cout << "=== INSERTING STRAGGLER ===" << std::endl;
        std::cout << "Straggler value: " << leftover << std::endl;
        size_t pos = 0;
        while (pos < vec_result.size() && vec_result[pos] < leftover) {
            m_comparaisons++;
            std::cout << "  Comparing position " << pos << ": "
                      << vec_result[pos] << " < " << leftover << std::endl;
            pos++;
        }
        vec_result.insert(vec_result.begin() + pos, leftover);
        std::cout << "Inserted straggler at position " << pos << ": ";
        for (auto val : vec_result) std::cout << val << " ";
        std::cout << std::endl;
    }

    return vec_result;
}

std::deque<int> MergeSort::DgetInput()
{
	return deq_sequence;
}


std::deque<size_t> MergeSort::DgetJacobsthalOrder(size_t n) {
    if (n == 0)
        return std::deque<size_t>();

    std::deque<size_t> jacobstahl = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
    std::deque<size_t> order;
    std::deque<bool> used(n, false);

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


 std::deque<int> MergeSort::FJAlgoDeq(std::deque<int> input){
    if (input.size() <= 1) {
        return input;
    }

    std::deque<PairWithIndex> pairs;
    int  leftover = -1;
    bool has_leftover = false;

    std::deque<int> main_chain;
    std::deque<int> pend_chain;

    auto it = input.begin();
    while (it != input.end()) {
        auto first = it++;
        if (it == input.end()) {
            leftover = *first;
            has_leftover = true;
            break;
        }
        auto second = it++;

        PairWithIndex p;
        if (*first < *second) {
            std::swap(*first, *second);
        }
        p.main = *first;
        p.pend = *second;
        main_chain.push_back(*first);
        pend_chain.push_back(*second);
        p.originalIndex = pairs.size();
        pairs.push_back(p);
    }

    main_chain = FJAlgoDeq(main_chain);


    d_result = main_chain;


    if (!pairs.empty()) {
        d_result.insert(d_result.begin(), pairs[0].pend);
    }

    d_order = DgetJacobsthalOrder(pend_chain.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        if (idx == 0)
            continue;
        if (idx >= pairs.size())
            continue;

        int toInsert = pairs[idx].pend;
        int pairBigger = pairs[idx].main;


        size_t maxPos = 0;
        for (size_t j = 0; j < d_result.size(); j++) {
            if (vec_result[j] == pairBigger) {
                maxPos = j;
                break;
            }
        }

        size_t left = 0;
        size_t right = maxPos + 1;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            auto mid_it = d_result.begin();
            std::advance(mid_it, mid);
            m_comparaisons++;
            if (*mid_it < toInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        d_result.insert(d_result.begin() + left, toInsert);
    }

    if (has_leftover) {
        size_t pos = 0;
        while (pos < d_result.size() && vec_result[pos] < leftover) {
            m_comparaisons++;
            pos++;
        }
        d_result.insert(d_result.begin() + pos, leftover);
    }

    return d_result;
}

