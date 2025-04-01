// This is the input/output stream library
#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)toupper(argv[i][j]);
			j++;
		}
		if (i < argc - 1)
			std::cout << " ";
		i++;
	}
	}
	std::cout << std::endl;
}