#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

// Binary insertion helper
void insertInSortedOrder(std::vector<int>& vec, int value) {
    auto pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}

// Simple Jacobsthal order generator (naive version for demo)
std::vector<int> jacobsthalOrder(int n) {
    std::vector<int> order;
    for (int i = 1; i < n; ++i) order.push_back(i);
    if (n > 0) order.push_back(0);
    return order;
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

void fordJohnsonSort(std::vector<int>& mainChain, std::vector<int>& pendChain) {
    if (mainChain.size() <= 2)
        return;

    // Form subpairs for recursion
    std::vector<int> subMain, subPend;
    for (size_t i = 0; i + 1 < mainChain.size(); i += 2) {
        if (mainChain[i] > mainChain[i+1]) {
            subMain.push_back(mainChain[i]);
            subPend.push_back(mainChain[i+1]);
        } else {
            subMain.push_back(mainChain[i+1]);
            subPend.push_back(mainChain[i]);
        }
    }

    // Recurse
    fordJohnsonSort(subMain, subPend);

    // Now mirror sort and reinsert pendings at this level
    recursiveSort(subMain, subPend);
    mainChain = insertPendings(subMain, subPend);
}


int main() {
    // Example input: mainChain = bigger elements, pendChain = smaller elements
    std::vector<int> mainChain = {5, 9, 4};
    std::vector<int> pendChain = {3, 7};

    // Step 1: recursive sort of mainChain with mirroring
    recursiveSort(mainChain, pendChain);
    // Step 2: insert pendings in Jacobsthal order
    std::vector<int> sorted = insertPendings(mainChain, pendChain);

    // Print result
    for (int x : sorted) std::cout << x << " ";
    std::cout << std::endl;
}