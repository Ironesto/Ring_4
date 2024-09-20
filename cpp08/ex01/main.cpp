#include "Span.hpp"

int main()
{
	try
	{
		Span s1(3);
		s1.addNumber(46);
		s1.addNumber(22);
		Span s2 = s1;
		s1.addNumber(333);
		s2.addNumber(48);
		s2.shortestSpan();
		s2.longestSpan();
	}
	catch (std::string &e)
	{
		std::cout << e;
	}
	return 0;
}