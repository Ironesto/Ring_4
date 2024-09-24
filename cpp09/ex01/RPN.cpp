#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &src) { *this = src; }
RPN &RPN::operator=(const RPN &src) { (void)src; return *this; }
RPN::~RPN() {}

int operations(int a, int b, char c)
{
	switch (c)
	{
	case '+':
		return (b + a);
	case '-':
		return (b - a);
	case '*':
		return (b * a);
	case '/':
		return (b / a);
	default:
		throw std::string("Error: operation not found");
		break;
	}
}

void RPN::doMaths(std::string src)
{
	if (src.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::string("Error");
	size_t len = 0;
	if (src.length() > 1)
	{
		while(len < src.length())
		{
			while (src[len] >= '0' && src[len] <= '9')
			{
				this->numbers.push(src[len] - '0');
				// std::cout << "top es " << this->numbers.top() << std::endl;
				len += 2;
			}
			if (this->numbers.size() < 2)
				throw std::string("Error: not enought arguments");
			int a = this->numbers.top();
			this->numbers.pop();
			int b = this->numbers.top();
			this->numbers.pop();
			std::cout << "a " << a << " b " << b << " oper " << src[len] << " res= " << operations(a, b, src[len]) << std::endl;
			this->numbers.push(operations(a, b, src[len]));
			len += 2;
		}
		if (this->numbers.size() != 1)
			throw std::string("Error");
		std::cout << this->numbers.top() << std::endl;
	}
	else if (src[0] >= '0' && src[0] <= '9')
		std::cout << src[0] << std::endl;
	else
		throw std::string("Error: only one argument and is invalid");
}