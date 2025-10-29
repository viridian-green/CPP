#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &oth)
{

}
	// BitcoinExchange &operator=(const BitcoinExchange &oth);
	BitcoinExchange::BitcoinExchange(){}
	BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::resetValues() {
	m_float_value = 0;
	m_int_value = 0;
}


void BitcoinExchange::parseLine(std::string line) {
	resetValues();
	size_t first_space = line.find(' ');
	size_t second_space = line.find(' ', first_space + 1);

	if (first_space == std::string::npos || second_space == std::string::npos)
	{
		std::cout << "Error. Format of each line should be 'date | value'" << std::endl;
		return;
	}

	std::string date = line.substr(0, first_space);
	std::string value = line.substr(second_space + 1);
	if (parseDate(date) && parseValue(value))
		calculateExchange();
}

void BitcoinExchange::calculateExchange() {

}

int BitcoinExchange::parseDate(std::string s) {
	size_t first_hyphen = s.find('-');
	size_t second_hyphen = s.find('-', first_hyphen + 1);

	if (first_hyphen == std::string::npos || second_hyphen == std::string::npos)
		std::cout << "Error: bad formatting of the date. It should be 'Year-Month-Day'." << std::endl;
	int month = std::atoi(s.substr(first_hyphen, second_hyphen).c_str());
	int day;
	// std::cerr << "Error: bad input" << s << std::endl;

	return 1;
}

bool BitcoinExchange::isValidFloat(const std::string &s) {
    static const std::regex floatPattern(R"(^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$)");
    	return std::regex_match(s, floatPattern);
}

bool BitcoinExchange::isValidInt(const std::string &s) {
    try {
        size_t pos;
        long val = std::stol(s, &pos); // use long to catch out-of-range before narrowing

        if (pos != s.size()) {
            std::cerr << "Error: invalid characters in number: " << s << std::endl;
            return false;
        }

        if (val > INT_MAX || val < INT_MIN) {
            std::cerr << "Error: Value out of int bounds: " << s << std::endl;
            return false;
        }

        m_int_value = static_cast<int>(val);
        return true;

    } catch (const std::exception &e) {
        std::cerr << "Error: invalid integer: " << s << std::endl;
        return false;
    }
}

bool BitcoinExchange::isNumber(const std::string& s) {
	size_t pos;
	long val = std::stol(s, &pos);

	 if (val > INT_MAX || val < INT_MIN) {
            std::cerr << "Error: Value out of int bounds: " << s << std::endl;
            return false;
        }

    std::string::const_iterator it = s.begin();


    while (it != s.end() && std::isdigit(*it)) ++it;
    	return !s.empty() && it == s.end();
}

int BitcoinExchange::parseValue(std::string s) {

	if (isNumber(s.c_str()))
	{
		std::cout << "test" <<
		m_int_value = atoi(s.c_str());
		// if (m_int_value == INT_MAX || m_int_value == INT_MIN)
		// {
		// 	std::cout << "Error: Value is out of bounds: " << s << std::endl;
		// 	return 0;
		// }
	}
	else if (isValidFloat(s))
		m_float_value = std::stof(s);
	else
	{
		std::cout << "Error: Value should be a positive number from 0 to 1000: " << s << std::endl;
		return 0;
	}

	if (m_float_value < 0 || m_int_value < 0)
	{
		std::cout << "Error: not a positive number: " << s << std::endl;
		return 0;
	}
	else if (m_float_value > 1000 || m_int_value > 1000)
	{
		std::cout << "Error: too large a number: " << s << std::endl;
		return 0;
	}

	return 1;
}