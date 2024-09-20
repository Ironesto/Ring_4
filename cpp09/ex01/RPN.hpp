#pragma once

#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<int> numbers;

	public:
		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void doMaths(std::string src);
};