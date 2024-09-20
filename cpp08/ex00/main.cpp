#include "easyfind.hpp"

int main()
{
	try
	{
		std::list<int> num;
		num.push_back(11);
		num.push_back(22);
		num.push_back(33);
		num.push_back(44);
		std::cout << "tying to find 22(its in)" << std::endl;
		int res =  easyfind(num, 22);
		std::cout << res << std::endl;
		std::cout << "tying to find 2(its not in)" << std::endl;
		res =  easyfind(num, 2);
		std::cout << res << std::endl;
	}
	catch (std::string &e)
	{
		std::cout << e;
	}
	return 0;
}