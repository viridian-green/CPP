#include "Span.cpp"
#include <iostream>

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

Span copy(sp);

Span assigned(5);
assigned = sp;


// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
return 0;
}