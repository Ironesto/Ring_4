#include "Iter.hpp"

int main()
{
	std::string array[3] = {"array 1", "length 23", "finish all"};
	iter(array, 3, func);
	int num[4] = {1, 2, 3, 42};
	iter(num, 4, func);
	return 0;
}