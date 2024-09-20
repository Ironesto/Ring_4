#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &src) { *this = src; }
RPN &RPN::operator=(const RPN &src) { (void)src; return *this; }
RPN::~RPN() {}

void RPN::doMaths(std::string src)
{
	std::cout << src << std::endl;
}