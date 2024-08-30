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
			throw std::string("Error: invalid argument");
		std::cout << "char: " << src[0] << std::endl;
		std::cout << "int: " << static_cast<int>(src[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(src[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(src[0]) << ".0" << std::endl;
	}
}

static void isNum(const std::string src, int k, bool dot)
{
	for (int i = k; src[i] != '\0'; i++)
	{
		if (src[i] == '.' && dot == true)
				throw std::string("Error: Two points");
		if (src[i] == '.' && dot == false)
			dot = true;
		if ((src[i] < '0' || src[i] > '9') && src[i] != '.')
		{
			if (src[i] == 'f' && src[i + 1] == '\0' && dot == true)
				continue ;
			else
				throw std::string("Error: Char in the number");
		}
	}
	double num = std::atof(src.c_str());
	std::cout << "char: ";
	if (num >= 32 && num <= 126)
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (num != static_cast<float>(num))
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	if (num != static_cast<int>(num))
		std::cout << "double: " << num << std::endl;
	else
		std::cout << "double: " << num << ".0" << std::endl;
	return ;
}

static void isDot(const std::string src, int i)
{
	if (src[i] == '.' && (src[i + 1] >= '0' && src[i + 1] <='9'))
		isNum(src, i + 1, true);
	else
		isChar(src);
}

static void isPlusMinus(const std::string src)
{
	if ((src[0] == '-' || src[0] == '+') && src[1] != '\0')
	{
		if (src[1] == '.')
			isDot(src, 1);
		else if (src[1] >= '0' && src[1] <= '9')
			isNum(src, 1, false);
		else
			isChar(src);
	}
	else
		isChar(src);
}

static bool pseudo(const std::string src)
{
	if (src == "-inff" || src == "+inff" || src == "inff" || src == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << src << std::endl;
		std::cout << "double: " << src.substr(0, src.length() - 1) << std::endl;
		return true;
	}
	if (src == "-inf" || src == "+inf" || src == "inf" || src == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << src << "f" << std::endl;
		std::cout << "double: " << src << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::Convert(const std::string src)
{
	try
	{
		if (pseudo(src) == true)
			return ;
		else if (src[0] == '+' || src[0] == '-')
			isPlusMinus(src);
		else if (src[0] == '.')
			isDot(src, 0);
		else if (src[0] >= '0' && src[0] <='9')
			isNum(src, 0, false);
		else
			isChar(src);
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
	
	
}