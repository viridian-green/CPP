#include "RPN.hpp"

	RPN::RPN(){}
	RPN::RPN(RPN const &other) : rpn_stack(other.rpn_stack){}
	RPN &RPN::operator=(RPN const &other) {
		if (this != &other)
		{
			rpn_stack = other.rpn_stack;
		}
		return (*this);
	}
	RPN::~RPN(){}

	int RPN::parseArgument(std::string arg) {
		std::istringstream stream(arg);
		std::string token;

		while (stream >> token)
		{
			if (std::isdigit(token[0]))
			{
				if (std::atoi(token.c_str()) <= 10)
					rpn_stack.push(std::atoi(token.c_str()));
			}
			else if (token == "+" || token == "-" || token == "/" || token == "*")
			{
				if (rpn_stack.size() < 2)
				{
					std::cerr << "Error there must be two digits before an operator" << std::endl;
					return 1;
				}

				std::cout << token[0] << std::endl;
				std::cout << token[1];
				int a = rpn_stack.top();
				rpn_stack.pop();
				int b = rpn_stack.top();
				rpn_stack.pop();



				if (token == "+")
					m_result = a + b;
				else if (token == "-")
					m_result = a - b;
				else if (token == "/")
				{
					if (b == 0)
					{
						std::cerr << "Error, you attempted to divide a number by 0" << std::endl;
						return 1;
					}
					else
						m_result = a / b;
				}
				else if (token == "*")
					m_result = a * b;
				rpn_stack.push(m_result);

			}
			else
			{
				std::cerr << "Error: invalid token: " << token << std::endl;
				return 1;
			}
			// while(!rpn_stack.empty())
			// {
			// 	std::stack s = rpn_stack.top();
			// 	std::cout << w;
			// 	rpn_stack.pop();
			// }



			}
			std::stack<int> temp = rpn_stack; // make a copy, so we don’t destroy the original
			while (!temp.empty()) {
				std::cout << temp.top() << " ";
				temp.pop();
			}
			std::cout << std::endl;
			std::cout << m_result << std::endl;
			return 0;


	}
