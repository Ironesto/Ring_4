#include "Span.hpp"

int main()
{
	try
	{
		Span s1(3);
		s1.addNumber(46);
		s1.addNumber(22);
		Span s2 = s1;
		//s1.addNumber(33);
		s1.addNumber(333);
		//s2.addNumber(44);
		s2.addNumber(45);
		s2.shortestSpan();	//sin terminar
		s2.longestSpan();
	}
	catch (std::string &e)
	{
		std::cout << e;
	}
	return 0;
}