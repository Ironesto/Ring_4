#include "Span.hpp"

Span::Span() { _n = 0; _num.reserve(0); }
Span::Span(unsigned int n) :_n(n) { this->_num.reserve(this->_n); }
Span::Span(const Span &src) { *this = src; }
Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_num.reserve(src._num.capacity());
		this->_num = src._num;
	}
	//std::cout << this->_num.capacity() << " src " << src._num.capacity();
	return *this;
}
Span::~Span() {}

void Span::addNumber(int i)
{
	if (this->_n > 0)
		this->_num.push_back(i);
	else
		throw std::string("Error: no enought space\n");
	this->_n--;
}

void Span::shortestSpan()
{
	std::vector<int> src = this->_num;
	std::sort(src.begin(), src.end());
	// for (size_t i = 0; i < src.capacity(); i++)
	// 	std::cout << "src[" << i << "] = " << src[i] << ", ";
	// std::cout << std::endl;
	size_t i = 0;
	int res = src[src.capacity() - 1] - src[0];
	while (i < src.capacity())
	{
		for (size_t j = i + 1; j < src.capacity(); j++)
		{
			if (src[j] - src[i] < res)
				res = src[j] - src[i];
		}
		i++;
	}
	std::cout << "shortest span: " << res << std::endl;
}

void Span::longestSpan()
{
	int min = *std::min_element(this->_num.begin(),this->_num.end());
	int max = *std::max_element(this->_num.begin(),this->_num.end());
	std::cout << "min: " << min << std::endl;
	std::cout << "max: " << max << std::endl;
	std::cout << "largest span: " << max - min << std::endl;
	//for (size_t i = 0; i < this->_num.capacity(); i++)
	//	std::cout << "src[" << i << "] = " << this->_num[i] << ", ";
}

