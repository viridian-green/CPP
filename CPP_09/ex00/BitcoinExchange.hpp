#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <regex>
#include <climits>

class BitcoinExchange{
	std::map<std::string, double> m_database;
	double m_value;
	double m_result;
	std::string m_date;
	std::string m_error_message;

	public:
	BitcoinExchange(const BitcoinExchange &oth);
	BitcoinExchange &operator=(const BitcoinExchange &oth);
	BitcoinExchange();
	~BitcoinExchange();

	void parseLine(std::string line);
	std::string trim(const std::string &s);
	void addDatabaseEntry(const std::string &date, const double &price);
	int isValidDate(std::string s);
	int parseValue(std::string s);
	void calculateExchange();
	bool isValidFloat(const std::string &s);
	bool isValidInt(const std::string &s);
	bool isNumber(const std::string& s);
	void resetValues();

};