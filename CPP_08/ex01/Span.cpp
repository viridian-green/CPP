#include "Span.hpp"

	Span::Span(){}

	Span::Span(unsigned int N) : size(N)
	{
		if (N == 0)
			throw std::invalid_argument("Span size cannot be zero");
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
		if (numbers.size() >= size)
			throw std::runtime_error("Error. Cannot add number because vector size was reached.");
		if (newNumber > INT_MAX || newNumber < INT_MIN)
			throw std::runtime_error("Error. Number added is out of range.");
		numbers.push_back(newNumber);
	}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin > end)
		throw std::invalid_argument("Error. Begin number cannot be bigger than end.");
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		addNumber(*it);
	}
}

	int Span::shortestSpan()
	{
		if (numbers.size() < 2)
			throw std::runtime_error("Error. There are too little numbers store in vector to perform this operation");
		int min = INT_MAX;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size() - 1; i++)
		{
			int diff = numbers[i + 1] - numbers[i];
			if (diff <= min)
				min = diff;
		}
		return (min);
	}

	int Span::longestSpan()
	{
		if (numbers.size() == 0 || numbers.size() == 1)
			throw std::runtime_error("Error. There are too little numbers store in vector to perform this operation");
		sort(numbers.begin(), numbers.end());
		return (numbers.back() - numbers[0]);
	}

