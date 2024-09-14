#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _src;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		void exchange(std::string src);
};
