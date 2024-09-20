#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::string("Error: invalid number of arguments");
		RPN oper;
		oper.doMaths(argv[1]);
	}
	catch(std::string &e)
	{
		std::cout << e << std::endl;
	}
	return 0;
}