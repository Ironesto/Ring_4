#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<char, int> _src;
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

	public:
		void Exchange(std::string src);
};
