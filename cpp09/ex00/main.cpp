#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: bad arguments" << std::endl;
		return 1;
	}
	BitcoinExchange bit;
	bit.exchange(argv[1]);
	return 0;
}