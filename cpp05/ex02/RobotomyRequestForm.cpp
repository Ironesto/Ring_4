#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "No one";
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExec() const
{
	std::srand (static_cast<unsigned int>(std::time(0)));
	std::cout << "[Drilling noises]" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed";
}
