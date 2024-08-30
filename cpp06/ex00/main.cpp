#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: bas arguments" << std::endl, 1);
	ScalarConverter::Convert(argv[1]);
	double a = -0;
	std::cout << a<<std::endl;
	return 0;
}