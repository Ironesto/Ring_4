#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack() {}
		MutantStack(const MutantStack &src) { *this = src; }
		MutantStack &operator=(const MutantStack &src) { (void)src; return *this; }
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}