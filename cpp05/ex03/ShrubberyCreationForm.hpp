#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		void beExec() const;
};