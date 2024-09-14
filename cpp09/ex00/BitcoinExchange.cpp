#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) { (void)src; return *this; }
BitcoinExchange::~BitcoinExchange() {}

static int validMonth(std::string m)
{
	std::string aux = m.substr(5, 6);
	int digit = std::atoi(aux.data());
	if (digit <= 0 || digit > 12)
		throw std::string("Error: bad input => " + m);
	return 0;
}

static std::string getKey(std::string src)
{
	int i = 0;
	std::string res;
	while (src[i] != '|' && src[i])
		i++;
	res = src.substr(0, i);
	if (res.length() != 11)
		throw std::string("Error: bad input => " + res);
	validMonth(res);
	return res;
}

static double getValue(std::string src)
{
	double res = -1;
	std::string str;
	if (src.length() > 11 && src[11] == '|')
	{
		str = src.substr(12, src.length());
		res = atof(str.data());
	}
	else
		return -1;
	if (res < 0)
		throw	std::string("Error: not a positive number.");
	if (res > 2147483647)
		throw	std::string("Error: too large a number.");
	return res;
}

void BitcoinExchange::exchange(std::string src)
{
	std::ifstream ifs(src.data());
	std::string str;
	double i = -1;

	std::getline(ifs, str);
	while(std::getline(ifs, str))
	{
		try
		{
			i = getValue(str);
			str = getKey(str);
			std::cout << str << "=> ";
			this->_src[str] = i;
			std::cout << this->_src[str] << std::endl;
		}
		catch(std::string &e)
		{
			this->_src[str] = -1;
			std::cout << e << std::endl;
		}
	}
}
