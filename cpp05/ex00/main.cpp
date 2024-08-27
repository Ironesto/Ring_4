#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n| Test 1|" << std::endl;
		Bureaucrat B1("Rodolfo", 1);
		try
		{
			std::cout << B1 << std::endl;
			std::cout << "Felicidades! Vas a ser ascendido" << std::endl;
			B1.ascent();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más alto burócrata" << std::endl;
			std::cout << B1 << std::endl;
		}
	}
	{
		std::cout << "\n| Test 2|" << std::endl;
		Bureaucrat B0("Ramón", 150);
		Bureaucrat B1(B0);
		try
		{
			std::cout << B1 << std::endl;
			std::cout << "Lo siento! Vas a ser degradado" << std::endl;
			B1.descent();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más bajo burócrata(si sigues así serás despedido)" << std::endl;
			std::cout << B1 << std::endl;
		}
	}
	{
		std::cout << "\n| Test 3|" << std::endl;
		Bureaucrat B0("Rodrigo", 43);
		Bureaucrat B1 = B0;
		try
		{
			std::cout << B1 << std::endl;
			std::cout << "Felicidades! Vas a ser ascendido" << std::endl;
			B1.ascent();
			std::cout << B1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más alto burócrata" << std::endl;
			std::cout << B1 << std::endl;
		}
			std::cout << B0 << std::endl;
			std::cout << B1 << std::endl;
	}
	{
		std::cout << "\n| Test 4|" << std::endl;
		Bureaucrat B1("Roberto", 42);
		try
		{
			std::cout <<B1 << std::endl;
			std::cout << "Lo siento! Vas a ser degradado" << std::endl;
			B1.descent();
			std::cout << B1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más bajo burócrata(si sigues así serás despedido)" << std::endl;
			std::cout << B1 << std::endl;
		}
	}
}