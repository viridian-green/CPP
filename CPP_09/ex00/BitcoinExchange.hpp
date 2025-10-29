#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <climits>

class BitcoinExchange{
	std::map<std::string, std::string> database;
	float m_float_value;
	int m_int_value;

	public:
	BitcoinExchange(const BitcoinExchange &oth);
	BitcoinExchange &operator=(const BitcoinExchange &oth);
	BitcoinExchange();
	~BitcoinExchange();

	void parseLine(std::string line);
	int parseDate(std::string s);
	int parseValue(std::string s);
	void calculateExchange();
	bool isValidFloat(const std::string &s);
	bool isValidInt(const std::string &s);
	bool isNumber(const std::string& s);
	void resetValues();

};