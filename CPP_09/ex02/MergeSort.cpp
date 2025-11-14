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




std::vector<int> MergeSort::FJAlgo(const std::vector<int>& input)
{
    // base case
    if (input.size() <= 1)
        return input;

    std::vector<Pair> pairs = make_pairs(input);

    // extract main and pend values
    std::vector<int> main_chain = find_main(pairs);
    std::vector<int> pend_chain = find_pend(pairs);


    std::cout << "Pend: ";
	for (int x : pend_chain) {
		std::cout << x << ".";
	}
	std::cout << "\n";

    std::cout << "Main: ";
	for (int x : main_chain) {
		std::cout << x << ".";
	}
	std::cout << "\n";


    // recursively pair and sort the pend chain
    std::vector<int> sorted_main = FJAlgo(main_chain);

    std::cout << "Sorted_main: ";
	for (int x : sorted_main) {
		std::cout << x << ".";
	}
	std::cout << "\n";

    // for (const auto& p : sorted_main) {
    //     std::cout << "(" << p.a << ", " << p.b << ")" << std::endl;
    // }

    // now reorder original pairs according to sorted pend values
    std::vector<Pair> out;
    out.reserve(pairs.size());

    // for (const auto& sp : sorted_main) {
    //     for (const auto& orig : pairs) {
    //         if (sp.b == orig.b) {
    //             out.push_back(orig);
    //             break;
    //         }
    //     }
    // }

    return sorted_main;
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

std::vector<Pair> MergeSort::make_pairs(const std::vector<int>& nums)
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





