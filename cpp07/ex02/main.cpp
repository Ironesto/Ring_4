#include "Array.hpp"

int main()
{
	{
		try
		{
			std::cout << "\t--Test 1--" << std::endl;
			int n = 3;
			Array<std::string> str(n);
			str[0] = "hola";
			str[1] = "mundo";
			str[2] = "que tal";
			for (int i = 0; i <= n; i++)
				std::cout << "str[" << i << "]: " << str[i] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "\t--Test 2--" << std::endl;
			int n = 4;
			Array<int> num(n);
			num[0] = 0;
			num[1] = 1;
			num[2] = 123;
			num[3] = 42;
			for (int i = 0; i <= n; i++)
				std::cout << "num[" << i << "]: " << num[i] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}