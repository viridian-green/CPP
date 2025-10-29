#include <iostream>
#include "BitcoinExchange.cpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error you must input 'btc' and the name of a file." << std::endl;

	BitcoinExchange bce;

	std::ifstream inFile(av[1]);
	if (!inFile.is_open())
		std::cerr << "Error. Could not open file" << std::endl;
	std::string line;
	if (getline(inFile, line)) //Skipping the first line which declares the format
	{
		while (getline(inFile, line))
			bce.parseLine(line);
	}
	inFile.close();

}