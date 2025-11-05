#include <iostream>
#include "BitcoinExchange.cpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error you must input 'btc' and the name of a file." << std::endl;

	BitcoinExchange bce;

	std::ifstream db_file("data.csv");

	if (!db_file.is_open()) {
		std::cerr << "Error: could not open data.csv" << std::endl;
		return 1;
    }

	std::string line;
	getline(db_file, line);
	while (getline(db_file, line))
	{
		size_t comma = line.find(',');
		bce.addDatabaseEntry(line.substr(0, comma), std::atof(line.substr(comma + 1).c_str()));
	}
	db_file.close();

	std::ifstream input_file(av[1]);
	if (!input_file.is_open())
	{
		std::cerr << "Error. Could not open file" << std::endl;
		return 1;
	}

	getline(input_file, line); //Skipping the first line which declares the format
		while (getline(input_file, line))
		{	try
			{
				bce.parseLine(line);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	input_file.close();
}