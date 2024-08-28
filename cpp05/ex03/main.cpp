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
		AForm* rrf;
		try
		{
			rrf = i1.makeForm("Robotomy", "Ignacio");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (bool &e)
		{
			std::cout << "bool exception" << std::endl;
		}
	}
	return 0;
}