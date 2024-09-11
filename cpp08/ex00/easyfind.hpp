#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

template<typename T>
int easyfind(T &src, int i)
{
	typename T::iterator iter;

	iter = std::find(src.begin(), src.end(), i);
	if (i != *iter)
		throw (std::string ("Error: not found\n"));
	return *iter;
}