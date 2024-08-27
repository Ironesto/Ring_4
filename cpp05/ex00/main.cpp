#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n| Test 1|" << std::endl;
		Bureaucrat b1("Rodolfo", 1);
		try
		{
			std::cout << b1 << std::endl;
			std::cout << "Felicidades! Vas a ser ascendido" << std::endl;
			b1.ascent();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más alto burócrata" << std::endl;
			std::cout << b1 << std::endl;
		}
	}
	{
		std::cout << "\n| Test 2|" << std::endl;
		Bureaucrat b0("Ramón", 150);
		Bureaucrat b1(b0);
		try
		{
			std::cout << b1 << std::endl;
			std::cout << "Lo siento! Vas a ser degradado" << std::endl;
			b1.descent();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más bajo burócrata(si sigues así serás despedido)" << std::endl;
			std::cout << b1 << std::endl;
		}
	}
	{
		std::cout << "\n| Test 3|" << std::endl;
		Bureaucrat b0("Rodrigo", 43);
		Bureaucrat b1 = b0;
		try
		{
			std::cout << b1 << std::endl;
			std::cout << "Felicidades! Vas a ser ascendido" << std::endl;
			b1.ascent();
			std::cout << b1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más alto burócrata" << std::endl;
			std::cout << b1 << std::endl;
		}
			std::cout << b0 << std::endl;
			std::cout << b1 << std::endl;
	}
	{
		std::cout << "\n| Test 4|" << std::endl;
		Bureaucrat b1("Roberto", 42);
		try
		{
			std::cout <<b1 << std::endl;
			std::cout << "Lo siento! Vas a ser degradado" << std::endl;
			b1.descent();
			std::cout << b1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más bajo burócrata(si sigues así serás despedido)" << std::endl;
			std::cout << b1 << std::endl;
		}
	}
	{
		std::cout << "\n| Test 5|" << std::endl;
		Bureaucrat b1("Rigoberto", 0);
		try
		{
			std::cout <<b1 << std::endl;
			std::cout << "Lo siento! Vas a ser degradado" << std::endl;
			b1.descent();
			std::cout << b1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más bajo burócrata(si sigues así serás despedido)" << std::endl;
			std::cout << b1 << std::endl;
		}
	}
	{
		std::cout << "\n| Test 6|" << std::endl;
		Bureaucrat b1("Rubén", 165);
		try
		{
			std::cout <<b1 << std::endl;
			std::cout << "Lo siento! Vas a ser degradado" << std::endl;
			b1.descent();
			std::cout << b1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! Ya eres el más bajo burócrata(si sigues así serás despedido)" << std::endl;
			std::cout << b1 << std::endl;
		}
	}
	return 0;
}