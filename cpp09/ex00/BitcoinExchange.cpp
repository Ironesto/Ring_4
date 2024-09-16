#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) { (void)src; return *this; }
BitcoinExchange::~BitcoinExchange() {}

static std::map<std::string, double> getData()
{
	std::ifstream ifs("data.csv");
	std::map<std::string, double> res;
	std::string src;
	std::string num;
	getline(ifs, src);
	while(getline(ifs, src))
	{
		num = src.substr(11);
		res[src.substr(0, 10)] = std::atof(num.data());
	}
	return res;
}

static int validArg(std::string src)
{
	if (src.length() < 14)
		return 1;
	for (int aux[8] = {0, 1, 2, 3, 5, 6, 8, 9}, i = 0; i < 8; i++)
	{
		if (src[aux[i]] < '0' || src[aux[i]] > '9')	//check date is digit
			return 1;
	}
	if (src[4] != '-' || src[7] != '-')				//check separator as '-'
		return 1;
	if (src[10] != ' ' || src[12] != ' ')			//check spaces before and after '|'
		return 1;
	if (src[11] != '|')								//check key-value separator
		return 1;
	for (int dot = 0, i = 13; src[i]; i++)			//check value of value parameter
	{	
		if (src[i] == '.')
			dot++;
		if (((src[i] <'0' || src[i] >'9') && src[i] != '.' && src[i] != '+' && src[i] != '-') || dot == 2)
			return 1;
	}
	return 0;
}

static int validMonth(std::string m)
{
	int digit = std::atoi(m.data());
	if (digit <= 0 || digit > 12)
		return 1;
	return 0;
}

static int validDay(std::string y, std::string m, std::string d)
{
	int year = std::atoi(y.data());
	int month = std::atoi(m.data());
	int day = std::atoi(d.data());

	int num[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0)				//check leap year
		if (year % 100 == 0)
			if (year % 400 == 0)
				num[1] = 29;
			else num[1] = 28;
		else num[1] = 29;
	else num[1] = 28;
	if (day > num[month - 1] || validMonth(m) == 1)
		return 1;
	return 0;
}

static void validations(std::string src)
{
	if (validArg(src) == 1)
		throw std::string("Error: bad input => " + src);
	std::string year = src.substr(0, 4);
	std::string month = src.substr(5, 6);
	std::string day = src.substr(8, 9);
	if (validDay(year, month, day) == 1)
		throw std::string("Error: bad input => " + src);
}

static std::string getKey(std::string src)
{
	int i = 0;
	std::string res;
	while (src[i] != '|' && src[i])
		i++;
	res = src.substr(0, i - 1);
	if (res.length() != 10)
		throw std::string("Error: bad input => " + res);
	return res;
}

static double getValue(std::string src)
{
	double res = -1;
	std::string str;
	str = src.substr(12, src.length());
	res = atof(str.data());
	if (res < 0)
		throw	std::string("Error: not a positive number.");
	if (res > 1000)
		throw	std::string("Error: too large a number.");
	return res;
}

static std::map<std::string, double>::iterator noFindDate(std::map<std::string, double> src, std::string str)
{
	std::map<std::string, double>::iterator it = src.begin();
	while (it != src.end())
	{
		if (it->first > str)
			break;
		*it++;
	}
	if (it != src.begin())
		*it--;
	else
		throw std::string("Error: out of range");
	return it;
}

static void findDate(std::map<std::string, double> src, std::string str, double i)
{
	if (src.find(str) != src.end())
		std::cout << src.find(str)->first << " => "
		<< i << " = "<< src.find(str)->second * i <<std::endl;
	else
		std::cout << noFindDate(src, str)->first << " => "
		<< i << " = "<< noFindDate(src, str)->second * i <<std::endl;
}

void BitcoinExchange::exchange(std::string src)
{
	std::ifstream ifs(src.data());
	std::string str;
	double i;

	this->_src = getData();
	std::getline(ifs, str);
	while(std::getline(ifs, str))
	{
		try
		{
			validations(str);
			i = getValue(str);
			str = getKey(str);
			findDate(this->_src, str, i);
		}
		catch(std::string &e)
		{
			this->_src[str] = -1;
			std::cout << e << std::endl;
		}
	}
}
