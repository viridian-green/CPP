#pragma once
#include <string>
#include <sstream>
#include <stack>
#include <iostream>

class RPN {

	std::stack<int> rpn_stack;
	int m_result;

	public:
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);
	RPN();
	~RPN();

	int parseArgument(std::string argument);

};
