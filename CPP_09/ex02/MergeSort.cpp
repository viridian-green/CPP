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


 std::vector<int> MergeSort::jacobsthalOrder(size_t n) {
    std::vector<int>  order;
    if (n == 0)
        return order;
    std::vector<int>  jacob;
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

// std::vector<int> MergeSort::FJAlgo(const std::vector<int>& input)
// {
//     // base case
//     if (input.size() <= 1)
//     {
//         return input;
//     }

//     std::vector<Pair> pairs = make_pairs(input);

//     std::vector<int> main_chain = find_main(pairs); // bigger values
//     std::vector<int> pend_chain = find_pend(pairs); // smaller values

//     std::vector<int> sorted_main = FJAlgo(main_chain);


//     std::cout << "Sorted_main: ";
// 	for (int x : sorted_main) {
// 		std::cout << x << ".";
// 	}
// 	std::cout << "\n";
//     std::vector<int> order = jacobsthalOrder(pend_chain.size());
//     for (size_t idx : order) {
//         int val = pend_chain[idx];
//         std::cout << val << std::endl;
//         // find its corresponding main partner
//         int partner = main_chain[idx];
//         std::cout << partner << std::endl;
//         // binary search upper bound for where to insert val
//         auto pos = std::upper_bound(sorted_main.begin(), sorted_main.end(), partner);
//         sorted_main.insert(pos, val);
//     }

//     // Handle leftover if odd
// if (input.size() % 2 == 1) {
//     int leftover = input.back();
//     auto pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), leftover);
//     sorted_main.insert(pos, leftover);
// }


// //     for (size_t k : jacobsthalOrder(pend_chain.size())) {
// //     int value = pend_chain[k];
// //     int sponsor = pairs[k].b; // Correct sponsor is main value ('b')

// //     // Locate sponsor in sorted_main
// //     auto sponsor_it = std::find(sorted_main.begin(), sorted_main.end(), sponsor);

// //     // Insert value using lower_bound between...
// //     auto insert_pos = std::lower_bound(sorted_main.begin(), sponsor_it, value);
// //     sorted_main.insert(insert_pos, value);
// // }



// //     if (input.size() % 2 == 1) {
// //         int leftover = input.back();
// //         auto pos = std::lower_bound(main_chain.begin(), main_chain.end(), leftover);
// //         sorted_main.insert(pos, leftover);
// // }

//     // std::cout << "Sorted_main: ";
// 	// for (int x : main_chain) {
// 	// 	std::cout << x << ".";
// 	// }
// 	// std::cout << "\n";

//     //  std::cout << "pend_chain: ";
// 	// for (int x : pend_chain) {
// 	// 	std::cout << x << ".";
// 	// }
// 	// std::cout << "\n";


//     // for (const auto& p : sorted_main) {
//     //     std::cout << "(" << p.a << ", " << p.b << ")" << std::endl;
//     // }

//     // now reorder original pairs according to sorted pend values
//     // std::vector<Pair> out;
//     // out.reserve(pairs.size());

//     // for (const auto& sp : sorted_main) {
//     //     for (const auto& orig : pairs) {
//     //         if (sp.b == orig.b) {
//     //             out.push_back(orig);
//     //             break;
//     //         }
//     //     }
//     // }

//     return sorted_main;
// }



std::vector<int> MergeSort::FJAlgo(const std::vector<int>& input)
{
    // Base case
    if (input.size() <= 2)
        return input;

    // Step 1: make pairs
    std::vector<Pair> pairs = make_pairs(input);

    // Step 2: split main (larger) and pend (smaller)
    std::vector<int> main_chain = find_main(pairs);  // a_i
    std::vector<int> pend_chain = find_pend(pairs);  // b_i

    // Step 3: recursively sort the main chain
    std::vector<int> sorted_main = FJAlgo(main_chain);


    std::cout << "Sorted_main: ";
	for (int x : sorted_main) {
		std::cout << x << ".";
	}

    // Insert pend elements **now, before returning**
std::vector<int> order = jacobsthalOrder(pend_chain.size());
for (size_t idx : order) {
    int val = pend_chain[idx];

    // Insert relative to the main element in sorted_main
    // **Use the index in sorted_main that matches a_i**, NOT the original pairs[idx].a
    auto partner_it = std::find(sorted_main.begin(), sorted_main.end(), main_chain[idx]);
    if (partner_it == sorted_main.end()) partner_it = sorted_main.end();

    sorted_main.insert(partner_it, val);
}

    // std::cout << "Sorted_main: ";
	// for (int x : sorted_main) {
	// 	std::cout << x << ".";
	// }
	// std::cout << "\n";

return sorted_main;



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





