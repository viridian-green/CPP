#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MergeSort.hpp"
#include "MergeSort.cpp"
#include <vector>
#include <deque>
#include <list>


TEST_CASE("Ford-Johnson sorting large input", "[ford-johnson][stress]") {
    const int N = 3000;
    std::vector<int> input(N);

    // Fill with numbers 0..2999
    std::iota(input.begin(), input.end(), 0);

    // Shuffle randomly to create an unsorted input
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(input.begin(), input.end(), g);

    // Copy for expected output
    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    // Sort with your Ford–Johnson algorithm
    std::vector<int> result = fordJohnsonSort();

    // Check the result matches std::sort output
    REQUIRE(result.size() == expected.size());
    REQUIRE(result == expected);
}
