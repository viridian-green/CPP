// This is the input/output stream library
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			cout << (char)toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	}
	std::cout << std::endl;
}