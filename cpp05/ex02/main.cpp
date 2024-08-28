#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "\n| Test 1|" << std::endl;
		Bureaucrat b1("Paco", 1);
		PresidentialPardonForm presi("Eustaquio");
		try
		{
			std::cout << b1.getName() << " debes firmar " << presi.getName() << std::endl;
			b1.signForm(presi);
			b1.executeForm(presi);
			std::cout << std::endl << presi << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << presi << std::endl;
		}
		catch (bool &e)
		{
			std::cout << "bool exception" << std::endl;
			std::cout << presi << std::endl;
		}
	}
	{
		std::cout << "\n| Test 2|" << std::endl;
		Bureaucrat b1("Paco", 20);
		PresidentialPardonForm presi;
		try
		{
			std::cout << b1.getName() << " debes firmar " << presi.getName() << std::endl;
			b1.signForm(presi);
			b1.executeForm(presi);
			std::cout << std::endl << presi << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << "string exception" << std::endl;
			std::cout << e << std::endl;
			std::cout << presi << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << presi << std::endl;
		}
	}
	{
		std::cout << "\n| Test 3|" << std::endl;
		Bureaucrat b1("Sr. Zaphod", 20);
		Bureaucrat b2("Paco",42);
		RobotomyRequestForm robo("Jacinto");
		try
		{
			std::cout << b1.getName() << " debes firmar " << robo.getName() << std::endl;
			b2.signForm(robo);
			b2.executeForm(robo);
			std::cout << std::endl << robo << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << robo << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << "string exception" << std::endl;
			std::cout << e << std::endl;
			std::cout << robo << std::endl;
			b1.executeForm(robo);
		}
	}
	{
		std::cout << "\n| Test 4|" << std::endl;
		Bureaucrat b1("Sr. Zaphod", 20);
		Bureaucrat b2("Paco",42);
		ShrubberyCreationForm robo("Arbolito");
		try
		{
			std::cout << b1.getName() << " debes firmar " << robo.getName() << std::endl;
			b2.signForm(robo);
			b2.executeForm(robo);
			std::cout << std::endl << robo << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			std::cout << robo << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << "string exception" << std::endl;
			std::cout << e << std::endl;
			std::cout << robo << std::endl;
			b1.executeForm(robo);
		}
	}
	return 0;
}