#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

struct Pair {
    int a;  // main element (larger)
    int b;  // pending element (smaller)
};

std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << "(" << p.a << ", " << p.b << ")";
    return os;
}

// Binary insertion helper
void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}

// Compute a simple Jacobsthal order for n elements
std::vector<int> jacobsthalOrder(int n) {
    // For simplicity, we'll use a naive order [1,2,...,n-1,0]
    // Replace with actual Jacobsthal sequence if needed
    std::vector<int> order;
    for (int i = 1; i < n; ++i) order.push_back(i);
    order.push_back(0);
    return order;
}

// Recursive Ford-Johnson sort on vector of pairs
std::vector<int> fordJohnsonSort(std::vector<Pair>& pairs) {
    // Base case
    if (pairs.size() == 1) {
        return {pairs[0].a};
    }


    // 1. Extract main chain (a's) and pair them recursively
 std::vector<Pair> nextLevelPairs;
std::vector<int> pendings; // store smaller "a"s for later insertion

for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    Pair bigger = pairs[i];
    Pair smaller = pairs[i + 1];

    if (smaller.a > bigger.a)
        std::swap(bigger, smaller);

    nextLevelPairs.push_back(bigger);
    pendings.push_back(smaller.a);
	pendings.push_back(smaller.b); // keep smaller main element for later
}

    // Handle odd leftover
    Pair leftover;
    bool hasLeftover = pairs.size() % 2 == 1;
    if (hasLeftover) leftover = pairs.back();

    // Recursively sort next level mains
    std::vector<int> sortedMains = fordJohnsonSort(nextLevelPairs);

    // 2. Reorder current level pairs according to sorted mains
    std::vector<Pair> orderedPairs;
std::vector<bool> used(pairs.size(), false);

for (int val : sortedMains) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!used[i] && pairs[i].a == val) {
            orderedPairs.push_back(pairs[i]);
            used[i] = true;
            break;
        }
    }
}
    if (hasLeftover && leftover.a != leftover.b)
    	orderedPairs.push_back(leftover);

	std::vector<int> result;
for (auto& p : orderedPairs)
    result.push_back(p.a);

std::vector<int> order = jacobsthalOrder(orderedPairs.size());
for (int idx : order) {
    if (idx < orderedPairs.size())
        insertInSortedOrder(result, orderedPairs[idx].b);
}

// also insert pendings
	for (int val : pendings)
		insertInSortedOrder(result, val);
	return result;
}

int main() {
    std::vector<int> input = {3, 5, 9, 7, 4};

    // Form pairs
    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i+1])
            pairs.push_back({input[i], input[i+1]});
        else
            pairs.push_back({input[i+1], input[i]});
    }

    // Handle leftover
    if (input.size() % 2 == 1) {
        pairs.push_back({input.back(), input.back()}); // duplicate a for leftover
    }

	// for (Pair p : pairs) std::cout << p << " ";
    // std::cout << "\n";


    // Sort
    std::vector<int> sorted = fordJohnsonSort(pairs);

    // Print
    for (int x : sorted) std::cout << x << " ";
    std::cout << "\n";
}