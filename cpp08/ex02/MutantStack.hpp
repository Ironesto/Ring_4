#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack() {};
		MutantStack(const MutantStack &src) { *this = src };
		MutantStack &operator=(const MutantStack &src) { (void)src; return *this; };
		~MutantStack() {};


};