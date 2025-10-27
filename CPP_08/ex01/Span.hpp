#pragma once
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>

class Span
{
	private:
	std::vector<int> numbers;
	unsigned int size;

	public:
	Span();
	Span(unsigned int N);
	Span(const Span &oth);
	Span &operator=(const Span &oth);
	~Span();
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void addNumber(int newNumber);
	int shortestSpan();
	int longestSpan();
};