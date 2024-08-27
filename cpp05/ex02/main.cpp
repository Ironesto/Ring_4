#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

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
			std::cout << "exception" << std::endl;
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
		catch (std::exception &e)
		{
			std::cout << "exception" << std::endl;
			std::cout << presi << std::endl;
		}
	}
	return 0;
}