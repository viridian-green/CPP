#include "MergeSort.hpp"


// MergeSort::MergeSort(const MergeSort &oth){}

// MergeSort &MergeSort::operator=(const MergeSort &oth){}

// MergeSort::~MergeSort(){}


//For debug purposes
std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << "(" << p.a << ", " << p.b << ")";
    return os;
}

// Container MergeSort::getResult()
// {
// 	return m_result;
// }

std::vector<int> MergeSort::find_pend(const std::vector<Pair>& pairs)
{
    std::vector<int> pend_chain;
    pend_chain.reserve(pairs.size());

    for (const auto& p : pairs)
        pend_chain.push_back(p.a);

    return pend_chain;
}

std::vector<int> MergeSort::find_main(const std::vector<Pair>& pairs)
{
    std::vector<int> main_chain;
    main_chain.reserve(pairs.size());

    for (const auto& p : pairs)
        main_chain.push_back(p.b);

    return main_chain;
}
std::vector<int> flatten_pairs(const std::vector<Pair>& pairs) {
    std::vector<int> result;
    result.reserve(pairs.size() * 2);  // preallocate for efficiency

    for (const auto& p : pairs) {
        result.push_back(p.a);
        result.push_back(p.b);
    }

    return result;
}
std::vector<Pair> MergeSort::FJAlgo(const std::vector<Pair>& pairs)
{
    // base case
    if (pairs.size() <= 1)
        return pairs;

    // extract main and pend values
    std::vector<int> main_chain = find_main(pairs);
    std::vector<int> pend_chain = find_pend(pairs);

int straggler = -1;

if (main_chain.size() % 2 == 1) {
    straggler = main_chain.back();
    main_chain.pop_back();     // THIS LINE IS MISSING IN YOUR CODE
}

std::vector<Pair> main_pairs = make_pairs(main_chain);

std::vector<Pair> sorted_main = FJAlgo(main_pairs);
std::vector<int> lower_sorted = flatten_pairs(FJAlgo(main_pairs)); // Or another method to flatten recursively
std::vector<int> main_sorted;
main_sorted.insert(main_sorted.end(), lower_sorted.begin(), lower_sorted.end());

// Now add current level (b values)
for (const Pair &p : sorted_main) {
    main_sorted.push_back(p.b);
}

// Insert straggler if needed
if (straggler != -1) {
    auto pos = std::lower_bound(main_sorted.begin(), main_sorted.end(), straggler);
    main_sorted.insert(pos, straggler);
}

// // Insert straggler
// if (straggler != -1) {
//     auto pos = std::lower_bound(main_sorted.begin(), main_sorted.end(), straggler);
//     main_sorted.insert(pos, straggler);
// }

       std::cout << "Sorted chain: ";
	for (int x : main_sorted) {
		std::cout << x << ".";
	}
	std::cout << "\n";

        std::cout << "Sorted chain: ";
	for (int x : main_sorted) {
		std::cout << x << ".";
	}
	std::cout << "\n";

    //don't forget to add the leftover

    // now reorder original pairs according to sorted pend values
    // std::vector<Pair> out;
    // out.reserve(pairs.size());

    // for (const auto& sp : sorted_main) {
    //     for (const auto& orig : pairs) {
    //         if (sp.b == orig.b) {
    //             out.push_back(orig);
    //             break;
    //         }
    //     }
    // }


    // for (const Pair &p : out) {
    // std::cout << p.a << p.b <<".";  // add b of pair
    // }


    return sorted_main;
}



std::vector<int> MergeSort::getInput()
{
	return m_sequence;
}

std::vector<int> MergeSort::jacobsthalOrder(size_t n) {
    std::vector<int> order;
    if (n == 0)
        return order;
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n - 1)
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);

    // The FJ algorithm uses Jacobsthal gaps to define insertion indices
    size_t last = 1;
    while (last < n) {
        size_t next = jacob[last];
        if (next > n - 1)
            next = n - 1;
        for (size_t i = next; i > jacob[last - 1]; --i)
            order.push_back(i);
        ++last;
    }

    return order;
};

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
     if (m_sequence.size() % 2 == 1)
        m_leftover = m_sequence.back();

	return 0;
};

MergeSort::MergeSort() {}

std::vector<Pair> MergeSort::make_pairs(const std::vector<int>& nums)
{
    std::vector<Pair> pairs;
    auto it = nums.begin();

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





