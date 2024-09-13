#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) { (void)src; return *this; }
BitcoinExchange::~BitcoinExchange() {}

static std::string GetKey(std::string src)
{
	int i = 0;
	std::string res;
	while (src[i] != '|' && src[i])
		i++;
	res = src.substr(0, i);
	return res;
}

static std::string GetValue(std::string src)
{
	int i = 0;
	std::string res;
	while (src[i])
		i++;
	std::cout << i << std::endl;
	res = src.substr(i, src.length());
	return res;
}

void BitcoinExchange::Exchange(std::string src)
{
	std::ifstream ifs(src.data());
	std::string str;
	//std::cout << "lee" << std::endl;
	//std::getline(ifs, str);
	//	std::cout << str << std::endl;
	while(std::getline(ifs, str))
	{
		this->_src[GetKey(str)] = GetValue(str);
		std::cout << this->_src[GetKey(str)] << std::endl;
		std::getline(ifs, str);
	}
	//std::cout << str << std::endl;
	//std::cout << ifs << std::endl;
}
