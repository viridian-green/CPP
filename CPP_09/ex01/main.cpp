#include "RPN.cpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error. Please input the name of the program and your RPN expression" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.parseArgument(av[1]);
}
