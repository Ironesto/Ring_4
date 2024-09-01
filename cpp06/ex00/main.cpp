#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: bad arguments" << std::endl, 1);
	ScalarConverter::Convert(argv[1]);
	return 0;
}