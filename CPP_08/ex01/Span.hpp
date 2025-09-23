#pragma once
#include <vector>

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

	void addNumber(int newNumber);
	int shortestSpan();
	int longestSpan();
};