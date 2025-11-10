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
}

// Recursive Ford-Johnson sort
std::vector<int> fordJohnsonSort(std::vector<Pair>& pairs, bool hasLeftover = false, int leftoverValue = -1) {
    // Base case
    if (pairs.size() == 1) {
        std::vector<int> base = {pairs[0].a, pairs[0].b};
        std::sort(base.begin(), base.end());
        if (hasLeftover)
            insertInSortedOrder(base, leftoverValue);
        return base;
    }

    std::vector<Pair> nextLevelPairs;
    std::vector<int> pendings;

    // Step 1: pair up and split into bigger/smaller
    for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
        Pair bigger = pairs[i];
        Pair smaller = pairs[i + 1];

        if (smaller.a > bigger.a)
            std::swap(bigger, smaller);

        nextLevelPairs.push_back(bigger);
        pendings.push_back(smaller.a);
        pendings.push_back(smaller.b);
    }

    // Step 2: handle odd leftover pair at this level
    bool newHasLeftover = pairs.size() % 2 == 1;
    int newLeftover = newHasLeftover ? pairs.back().a : -1;

    // Step 3: recursively sort next level
    std::vector<int> sortedMains = fordJohnsonSort(nextLevelPairs, newHasLeftover, newLeftover);

    // Step 4: reorder this level according to sorted mains
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

    // Step 5: build final result
    std::vector<int> result;
    for (auto& p : orderedPairs)
        result.push_back(p.a);

    // Jacobsthal order insertions
    std::vector<int> order = jacobsthalOrder(orderedPairs.size());
    for (int idx : order) {
        if (idx < (int)orderedPairs.size())
            insertInSortedOrder(result, orderedPairs[idx].b);
    }

    // Insert all pendings
    for (int val : pendings)
        insertInSortedOrder(result, val);

    // Finally, insert leftover from upper level
    if (hasLeftover)
        insertInSortedOrder(result, leftoverValue);

    return result;
}

int main() {
    std::vector<int> input = {3, 5, 9, 7, 4, 8, 13, 14};

    // Form initial pairs
    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] > input[i + 1])
            pairs.push_back({input[i], input[i + 1]});
        else
            pairs.push_back({input[i + 1], input[i]});
    }

    // Handle leftover as single value
    bool hasLeftover = input.size() % 2 == 1;
    int leftover = hasLeftover ? input.back() : -1;

    std::cout << "Initial pairs: ";
    for (Pair p : pairs) std::cout << p << " ";
    std::cout << "\n";

    // Sort
    std::vector<int> sorted = fordJohnsonSort(pairs, hasLeftover, leftover);

    // Print final sorted result
    std::cout << "Sorted: ";
    for (int x : sorted) std::cout << x << " ";
    std::cout << "\n";
}