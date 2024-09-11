#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int> _num;
		unsigned int _n;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int i);
		void shortestSpan();
		void longestSpan();
};