#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n| Test 1|" << std::endl;
		Bureaucrat b1("Rodolfo", 1);
		Form f1("LO", 1);
		try
		{
			std::cout << b1 << std::endl;
			std::cout << f1 << std::endl;
			std::cout << b1.getName() << " debes firmar " << f1.getName() << std::endl;
			b1.signForm(f1);
			std::cout << std::endl;
			std::cout << f1;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! no puedes firmarlo" << std::endl;
			std::cout << b1 << std::endl;
			std::cout << std::endl;
			std::cout << f1;
		}
	}
	{
		std::cout << "\n| Test 2|" << std::endl;
		Bureaucrat b0("Ramón", 120);
		Bureaucrat b1(b0);
		Form f0("Ley", 10);
		Form f1(f0);
		try
		{
			std::cout << b1 << std::endl;
			std::cout << f1 << std::endl;
			std::cout << b1.getName() << " debes firmar " << f1.getName() << std::endl;
			b1.signForm(f1);
			std::cout << std::endl;
			std::cout << f1;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! no puedes firmarlo" << std::endl;
			std::cout << b1 << std::endl;
			std::cout << std::endl;
			std::cout << f1;
		}
	}
	{
		std::cout << "\n| Test 3|" << std::endl;
		Bureaucrat b0("Rémulo", 33);
		Bureaucrat b1 = b0;
		Form f0("Real Decreto", 111);
		Form f1 = f0;
		try
		{
			std::cout << b1 << std::endl;
			std::cout << f1 << std::endl;
			std::cout << b1.getName() << " debes firmar " << f1.getName() << std::endl;
			b1.signForm(f1);
			std::cout << std::endl;
			std::cout << f1;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Vaya! no puedes firmarlo" << std::endl;
			std::cout << b1 << std::endl;
			std::cout << std::endl;
			std::cout << f1;
		}
	}
	return 0;
}