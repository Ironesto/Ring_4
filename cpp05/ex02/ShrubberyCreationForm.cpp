#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "No one";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beExec() const
{
	//terminar
}