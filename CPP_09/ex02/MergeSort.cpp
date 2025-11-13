#include "MergeSort.hpp"

// MergeSort::MergeSort(){}

// MergeSort::MergeSort(const MergeSort &oth){}

// MergeSort &MergeSort::operator=(const MergeSort &oth){}

// MergeSort::~MergeSort(){}


//For debug purposes
std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << "(" << p.a << ", " << p.b << ")";
    return os;
}

template <typename Container>
Container MergeSort<Container>::getResult()
{
	return m_result;
}

void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}

std::vector<size_t> MergeSort::jacobsthalOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;
    std::vector<size_t> jacob = {0, 1};
    while (jacob.back() < n - 1)
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);

    // The FJ algorithm uses Jacobsthal gaps to define insertion indices
    size_t last = 1;
    while (last < n) {
        size_t next = std::min(jacob[last], n - 1);
        for (size_t i = next; i > jacob[last - 1]; --i)
            order.push_back(i);
        ++last;
    }
    return order;
}




