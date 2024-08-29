#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) { *this = src; return *this; }
ScalarConverter::~ScalarConverter() {}

static void isChar (const std::string src)
{
	if ((src[0] >= 58 && src[0] <= 126) || (src[0] >= 32 && src[0] <= 47))
	{
		if (src[1] != '\0')
		{
			std::cerr << "Error: invalid argument" << std::endl;
			return ;
		}
		std::cout << src[0] << std::endl;
		std::cout << static_cast<int>(src[0]) << std::endl;
		std::cout << static_cast<double>(src[0]) << std::endl;
		std::cout << static_cast<float>(src[0]) << std::endl;
	}
	std::cout << "is char" << std::endl;
}

static void isNum(const std::string src)	//numeos negativos y el +
{
	bool dot = 0;
	for (int i = 0; src[i] != '\0'; i++)
	{
		if (src[i] == '.' && dot == false)
			dot = 1;
		else if (src[i] == '.' && dot == true)
				std::cerr << "two points" << std::endl;
		if ((src[i] < '0' || src[i] > '9') && src[i] != '.')
		{
			if (src[i] == 'f' && src[i + 1] == '\0' && dot == true)
				continue ;
			else
				std::cerr << "char in the num" << std::endl;
		}
	}
	double num = std::atof(src.c_str());
	if (num >= 32 && num <= 126)
		std::cout << static_cast<char>(num) << std::endl;
	else
		std::cout << "Impossible convert" << std::endl;
	std::cout << static_cast<int>(num) << std::endl;
	std::cout << num << std::endl;
	std::cout << static_cast<float>(num) << std::endl;
	std::cout << "is num" << std::endl;
}

static void isDot(const std::string src)	//numeos negativos y el +
{
	std::cout << "is dot" << std::endl;
	if (src[0] == '.' && (src[1] >= '0' && src[1] <='9'))
	{
		isNum(src);
		std::cout << std::atof(src.c_str()) << std::endl;
	}
	else
		isChar(src);
}

void ScalarConverter::Convert(const std::string src)
{
	if (src[0] == '.')	//numeos negativos y el +
		isDot(src);
	else if (src[0] >= '0' && src[0] <='9')	//numeos negativos y el +
		isNum(src);
	else
		isChar(src);
}