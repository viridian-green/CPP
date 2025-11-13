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

template <typename Container>
Container MergeSort<Container>::getInput()
{
	return m_sequence;
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

void binarySearch()
{

}




