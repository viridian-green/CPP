#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Span.hpp"

	Span::Span(){}

	Span::Span(unsigned int N) : size(N)
	{
		if (N < 0)
			throw std::out_of_range("Error. Index should be positive number.");
	}

	Span::Span(const Span &oth) : size(oth.size), numbers(oth.numbers){}

	Span &Span::operator=(const Span &oth)
	{
		if (&oth != this)
		{
			size = oth.size;
			numbers = oth.numbers;
		}
		return (*this);
	}

	Span::~Span(){}

	void Span::addNumber(int newNumber)
	{
		if (numbers.size() == size)
			throw std::runtime_error("Error. Vector ");
		numbers.push_back(newNumber);
	}

	int Span::shortestSpan()
	{
		if (numbers.size() == 0 || numbers.size() == 1)
			throw std::runtime_error("Error. There are too little numbers store in vector to perform this operation");

		std::vector<int>::iterator it;

	}

	// int Span::longestSpan()
	// {

	// }

	void Span::addNumbers(int begin, int end)
	{

	}