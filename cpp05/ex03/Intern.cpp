#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string namef, std::string target)
{
	RobotomyRequestForm *form;
	std::cout << form->getGradExe();
	std::cout << namef.find(" ")<< std::endl;
	std::cout << target<< std::endl;
	
	return form;
}