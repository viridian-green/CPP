#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

// Binary insertion helper
void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}

// // Simple Jacobsthal order generator (naive version for demo)
// std::vector<int> jacobsthalOrder(int n) {
//     std::vector<int> order;
//     for (int i = 1; i < n; ++i) order.push_back(i);
//     if (n > 0) order.push_back(0);
//     return order;
// }
// void fordJohnsonSort(std::vector<int>& mainChain, std::vector<int>& pendChain) {
//     if (mainChain.size() <= 2)
//         return;

// 	//TODO: Make the mirroring happen during the sort!
//     // Form subpairs for recursion
//     std::vector<int> subMain, subPend;
//     for (size_t i = 0; i + 1 < mainChain.size(); i += 2) {
//         if (mainChain[i] > mainChain[i+1]) {
//             subMain.push_back(mainChain[i]);
//             subPend.push_back(mainChain[i+1]);
//         } else {
//             subMain.push_back(mainChain[i+1]);
//             subPend.push_back(mainChain[i]);
//         }
//     }

//     // Recurse
//     fordJohnsonSort(subMain, subPend);

//     // Now mirror sort and reinsert pendings at this level
//     recursiveSort(subMain, subPend);
//     mainChain = insertPendings(subMain, subPend);
// }
void makePairs(const std::vector<int>& input,
               std::vector<int>& mainChain,
               std::vector<int>& pendChain)
{
    size_t n = input.size();
    for (size_t i = 0; i + 1 < n; i += 2) {
        int a = std::max(input[i], input[i + 1]);
        int b = std::min(input[i], input[i + 1]);
        mainChain.push_back(a);
        pendChain.push_back(b);
    }
    if (n % 2 != 0) {
        // If odd number, last one has no pair: treat as “pending”
        mainChain.push_back(input.back());
    }
}

// void insertInSortedOrder(std::vector<int>& vec, int value) {
//     auto pos = std::lower_bound(vec.begin(), vec.end(), value);
//     vec.insert(pos, value);
// }

std::vector<int> jacobsthalOrder(int n) {
    // Returns insertion order: 1, 3, 5, 2, 4... etc.
    std::vector<int> order;
    if (n == 0) return order;
    int a = 1, b = 1;
    while (a < n) {
        order.push_back(a - 1); // 0-indexed
        int tmp = a;
        a = b + 2 * a;
        b = tmp;
    }
    // Fill in missing indexes
    for (int i = 0; i < n; ++i)
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    return order;
}

std::vector<int> mergeInsertion(std::vector<int>& mainChain, std::vector<int>& pendChain) {
    std::vector<int> result = mainChain;
    std::vector<int> order = jacobsthalOrder(pendChain.size());

    for (int idx : order)
        if (idx < (int)pendChain.size())
            insertInSortedOrder(result, pendChain[idx]);

    return result;
}

void recursiveSort(std::vector<int>& mainChain, std::vector<int>& pendChain) {
    size_t n = mainChain.size();
    if (n <= 1) return;

    // Sort indexes by comparing mainChain values
    std::vector<size_t> indexes(n);
    for (size_t i = 0; i < n; ++i) indexes[i] = i;

    // Simple recursive sort (example: insertion for clarity)
    for (size_t i = 1; i < n; ++i) {
        size_t j = i;
        while (j > 0 && mainChain[indexes[j-1]] > mainChain[indexes[j]]) {
            std::swap(indexes[j-1], indexes[j]);
            j--;
        }
    }

    // Reorder mainChain and pendChain according to sorted indexes
    std::vector<int> newMain(n), newPend(n);
    for (size_t i = 0; i < n; ++i) {
        newMain[i] = mainChain[indexes[i]];
        newPend[i] = pendChain[indexes[i]];
    }
    mainChain = newMain;
    pendChain = newPend;
}

std::vector<int> insertPendings(const std::vector<int>& mainChain, const std::vector<int>& pendChain) {
    std::vector<int> result = mainChain;
    std::vector<int> order = jacobsthalOrder(pendChain.size());

    for (int idx : order) {
        if (idx < pendChain.size()) insertInSortedOrder(result, pendChain[idx]);
    }

    return result;
}

std::vector<int> fordJohnsonSort(std::vector<int> input)
{
    if (input.size() <= 2)
        return input; // base case, already sorted or trivial

    std::vector<int> mainChain, pendChain;
    makePairs(input, mainChain, pendChain);

    // Recurse on mainChain (bigger elements)
    std::vector<int> sortedMain = fordJohnsonSort(mainChain);

    // Mirror the order on pendChain (so pairs stay aligned)
    std::vector<int> mirroredPend(pendChain.size());
    for (size_t i = 0; i < pendChain.size() && i < sortedMain.size(); ++i)
        mirroredPend[i] = pendChain[i];

    // Backtrack: merge them using Jacobsthal insertion
    return mergeInsertion(sortedMain, mirroredPend);
}

int main() {
    // Example input: mainChain = bigger elements, pendChain = smaller elements
    std::vector<int> mainChain = {5, 9, 4, 17, 0, 21};
    std::vector<int> pendChain = {3, 7, 777, 45, 98};

    // Step 1: recursive sort of mainChain with mirroring
    recursiveSort(mainChain, pendChain);
    // Step 2: insert pendings in Jacobsthal order
    std::vector<int> sorted = insertPendings(mainChain, pendChain);

    // Print result
    for (int x : sorted) std::cout << x << " ";
    std::cout << std::endl;
}