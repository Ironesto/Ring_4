#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string namef, std::string target)
{
	std::string	options[] = {"robotomy request", "presidential request", "shrubbery request"};
	AForm *form = NULL;
	for (int i = 0; i <= 3; i++)
	{
		if (i == 3 || !namef.compare(options[i]))
		{
			switch (i)
			{
			case 0:
				form = new RobotomyRequestForm(target);
				break;
			case 1:
				form = new PresidentialPardonForm(target);
				break;
			case 2:
				form = new ShrubberyCreationForm(target);
				break;
			default:
				throw std::string("impossible request");
				break;
			}
			break;
		}
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}