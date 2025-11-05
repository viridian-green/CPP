#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &oth) : m_value(oth.m_value)
// , m_int_value(oth.m_int_value)
{}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &oth)
{
	if (this != &oth)
	{
		m_value = oth.m_value;
		// m_int_value = oth.m_int_value;
	}
	return *this;
}
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::resetValues() {;
	m_value = 0;
	m_error_message.clear();
	m_date.clear();
	m_result = 0;
}

void BitcoinExchange::addDatabaseEntry(const std::string &date, const double &price) {
	m_database.insert(std::make_pair(date, price));
}

std::string BitcoinExchange::trim(const std::string &s) {
	size_t start = 0;
	while (start < s.length() && std::isspace(s[start]))
		++start;
	size_t end = s.length();
	while (end > start && std::isspace(s[end - 1]))
		--end;
	return s.substr(start, end - start);
}

void BitcoinExchange::parseLine(std::string line) {
	resetValues();
	size_t first_space = line.find(' ');
	size_t pipe_pos = line.find('|');
	size_t second_space = line.find(' ', pipe_pos + 1);

	if (first_space == std::string::npos || pipe_pos == std::string::npos || second_space == std::string::npos )
	{
		std::cout << "Error: format of each line should be 'date | value'" << std::endl;
		return;
	}

	std::string date = trim(line.substr(0, first_space));
	std::string value = trim(line.substr(second_space + 1));
	if (isValidDate(date) && parseValue(value))
		calculateExchange();
	else
		std::cout << "Error : " << m_error_message << line << std::endl;
}

void BitcoinExchange::calculateExchange() {
	std::map<std::string, double>::iterator it = m_database.lower_bound(m_date);
	if (it == m_database.end()) //if all values are lower than m_date, chose closest lower
		it--;
	else if (it->first != m_date  && it != m_database.begin()) //if no values matches we choose the closest lower
		it--;
	m_result = m_value * it->second;
	std::cout << m_date << " => " << m_value << " = " << m_result << std::endl;

}

int BitcoinExchange::isValidDate(std::string date_str) {
	if (date_str.size() != 10 || date_str[4] != '-' || date_str[7] != '-')
        return 0;

    std::string yearStr = date_str.substr(0, 4);
    std::string monthStr = date_str.substr(5, 2);
    std::string dayStr = date_str.substr(8, 2);

    for (size_t i = 0; i < 4; ++i)
	{
        if (!std::isdigit(yearStr[i]))
			return 0;
	}
    for (size_t i = 0; i < 2; ++i)
	{
        if (!std::isdigit(monthStr[i]) || !std::isdigit(dayStr[i]))
			return 0;
	}

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

	if (month < 1 || month > 12)
		return 0;
	if (day < 1 || day > 31)
		return 0;
	if (year > 2025)
		return 0;
	m_date = date_str;
	return 1;
}

bool BitcoinExchange::isValidFloat(const std::string &s) {
    static const std::regex floatPattern(R"(^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$)");
    	return std::regex_match(s, floatPattern);
}


bool BitcoinExchange::isNumber(const std::string& s) {
	size_t pos;
	long val = std::stol(s, &pos);

	 if (val > INT_MAX || val < INT_MIN) {
            m_error_message = "value out of int bounds: ";
            return false;
        }

    std::string::const_iterator it = s.begin();

    while (it != s.end() && std::isdigit(*it)) ++it;
    	return !s.empty() && it == s.end();
}

int BitcoinExchange::parseValue(std::string value_str) {

	double value = std::atof(value_str.c_str());

	if (value < 0)
	{
		m_error_message = "not a positive number: ";
		return 0;
	}
	else if (value > 1000)
	{
		m_error_message = "too large a number: ";
		return 0;
	}

	m_value = value;

	return 1;
}