#define CATCH_CONFIG_MAIN  // This defines the main function for Catch2
#include "catch.hpp"
#include "Span.cpp"
#include <vector>
#include <stdexcept>

// Test case 1: Creating Span with zero size should throw an exception.
TEST_CASE("Span constructor throws exception for zero size", "[constructor]") {
    REQUIRE_THROWS_AS(Span(0), std::invalid_argument);
}

// Test case 2: Adding a number to Span.
TEST_CASE("Add single number", "[addNumber]") {
    Span span(5);
    span.addNumber(42);
    REQUIRE_THROWS_AS(span.shortestSpan(), std::runtime_error);
    REQUIRE_THROWS_AS(span.longestSpan(), std::runtime_error);
}

// Test case 3: Adding multiple// Test case 4: Adding more numbers than the size allows should throw an exception.
TEST_CASE("Add number beyond capacity", "[addNumber]") {
    Span span(3);
    span.addNumber(1);
    span.addNumber(2);
    span.addNumber(3);

    REQUIRE_THROWS_AS(span.addNumber(4), std::runtime_error);
}

TEST_CASE("Add multiple numbers", "[addNumber]") {
    Span span(5);
    span.addNumber(1);
    span.addNumber(3);
    span.addNumber(8);
    span.addNumber(2);
    span.addNumber(5);

    REQUIRE(span.shortestSpan() == 1);  // Between 1 and 2 or 2 and 3.
    REQUIRE(span.longestSpan() == 7);   // Between 1 and 8.
}

// Test case 5: Test with empty span.
TEST_CASE("Empty span should throw", "[empty]") {
    Span span(3);

    REQUIRE_THROWS_AS(span.shortestSpan(), std::runtime_error);
    REQUIRE_THROWS_AS(span.longestSpan(), std::runtime_error);
}

// Test case 6: Adding numbers with iterators.
TEST_CASE("Add numbers from iterator range", "[addNumbers]") {
    Span span(10);
    std::vector<int> numbers = {1, 3, 5, 7, 9};

    span.addNumbers(numbers.begin(), numbers.end());

    REQUIRE(span.shortestSpan() == 2);  // Between 3 and 5, or 5 and 7.
    REQUIRE(span.longestSpan() == 8);   // Between 1 and 9.
}

// Test case 8: Performance test with 10,000 numbers.
TEST_CASE("Performance test with 10,000 numbers", "[performance]") {
    Span span(10000);
    std::vector<int> numbers;

    // Generate a range of 10,000 numbers in ascending order.
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(i);
    }

    // Add numbers in bulk using iterators.
    span.addNumbers(numbers.begin(), numbers.end());

    // The shortest span should be 1 (between consecutive numbers).
    REQUIRE(span.shortestSpan() == 1);

    // The longest span should be the difference between the first and last number (0 and 9999).
    REQUIRE(span.longestSpan() == 9999);
}

// Test case 9: Copy constructor should work as expected.
TEST_CASE("Copy constructor test", "[copy]") {
    Span span1(5);
    span1.addNumber(10);
    span1.addNumber(20);

    Span span2(span1);  // Copy span1 to span2.

    REQUIRE(span2.shortestSpan() == 10);  // Difference between 10 and 20.
    REQUIRE(span2.longestSpan() == 10);   // Difference between 10 and 20.
}

// Test case 10: Assignment operator should work as expected.
TEST_CASE("Assignment operator test", "[assignment]") {
    Span span1(5);
    span1.addNumber(100);
    span1.addNumber(200);

    Span span2(5);
    span2 = span1;  // Assign span1 to span2.

    REQUIRE(span2.shortestSpan() == 100);  // Difference between 100 and 200.
    REQUIRE(span2.longestSpan() == 100);   // Difference between 100 and 200.
}

