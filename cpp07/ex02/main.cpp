#include "Array.hpp"

int main()
{
	try
	{
		Array<std::string> str(3);
		str[5] = "hola";
		std::cout << str[0] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}