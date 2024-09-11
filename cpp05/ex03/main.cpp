#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		std::cout << "\n| Test 1|" << std::endl;
		Intern i1;
		Bureaucrat b1("Sebastian", 20);
		Bureaucrat b2("Alejandro", 2);
		AForm* rrf = NULL;
		try
		{
			rrf = i1.makeForm("presidential request", "Ignacio");
			b1.signForm(*rrf);
			b2.executeForm(*rrf);
			std::cout << *rrf;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (bool &e)
		{
			std::cout << "bool exception" << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << e << std::endl;
		}
		if (rrf != NULL)
			delete rrf;
	}
	{
		std::cout << "\n| Test 2|" << std::endl;
		Intern i1;
		Bureaucrat b1("Sebastian", 20);
		AForm* rrf = NULL;
		try
		{
			rrf = i1.makeForm("robotomy request", "Ignacio");
			b1.signForm(*rrf);
			b1.executeForm(*rrf);
			std::cout << *rrf;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (bool &e)
		{
			std::cout << "bool exception" << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << e << std::endl;
		}
		if (rrf != NULL)
			delete rrf;
	}
	{
		std::cout << "\n| Test 3|" << std::endl;
		Intern i1;
		Bureaucrat b1("Sancho", 20);
		AForm* rrf = NULL;
		try
		{
			rrf = i1.makeForm("shrubbery request", "Garden");
			b1.signForm(*rrf);
			b1.executeForm(*rrf);
			std::cout << *rrf;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (bool &e)
		{
			std::cout << "bool exception" << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << e << std::endl;
		}
		if (rrf != NULL)
			delete rrf;
	}
	{
		std::cout << "\n| Test 4|" << std::endl;
		Intern i1;
		Bureaucrat b1("Sebastian", 20);
		AForm* rrf = NULL;
		try
		{
			rrf = i1.makeForm("void request", "Ignacio");
			b1.signForm(*rrf);
			b1.executeForm(*rrf);
			std::cout << *rrf;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (bool &e)
		{
			std::cout << "bool exception" << std::endl;
		}
		catch (std::string &e)
		{
			std::cout << e << std::endl;
		}
		if (rrf != NULL)
			delete rrf;
	}
	return 0;
}