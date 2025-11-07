#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

struct Pair {
    int a;  // main element (larger)
    int b;  // pending element (smaller)
};

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
    for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
        if (pairs[i].a > pairs[i+1].a)
            nextLevelPairs.push_back({pairs[i].a, pairs[i].b});
        else
            nextLevelPairs.push_back({pairs[i+1].a, pairs[i+1].b});
    }

    // Handle odd leftover
    Pair leftover;
    bool hasLeftover = pairs.size() % 2 == 1;
    if (hasLeftover) leftover = pairs.back();

    // Recursively sort next level mains
    std::vector<int> sortedMains = fordJohnsonSort(nextLevelPairs);

    // 2. Reorder current level pairs according to sorted mains
    std::vector<Pair> orderedPairs;
    for (int val : sortedMains) {
        for (auto it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->a == val) {
                orderedPairs.push_back(*it);
                pairs.erase(it);
                break;
            }
        }
    }
    if (hasLeftover) orderedPairs.push_back(leftover);

    // 3. Insert pending elements (b's) in Jacobsthal order
    std::vector<int> result;
    for (auto& p : orderedPairs) result.push_back(p.a);

    std::vector<int> order = jacobsthalOrder(orderedPairs.size());
    for (int idx : order) {
        if (idx < orderedPairs.size())
            insertInSortedOrder(result, orderedPairs[idx].b);
    }

    return result;
}

int main() {
    std::vector<int> input = {8, 5, 3, 7, 2, 4};

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

    // Sort
    std::vector<int> sorted = fordJohnsonSort(pairs);

    // Print
    for (int x : sorted) std::cout << x << " ";
    std::cout << "\n";
}