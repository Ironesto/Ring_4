#include "Iter.hpp"

int main()
{
	std::cout << "string test" << std::endl;
	std::string array[3] = {"array 1", "length 23", "finish all"};
	iter(array, 3, func);
	std::cout << std::endl;
	std::cout << "int test" << std::endl;
	int num[4] = {1, 2, 3, 42};
	iter(num, 4, func);
	return 0;
}