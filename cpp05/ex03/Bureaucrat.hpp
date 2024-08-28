#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const   std::string _name;
		int     _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void ascent();
		void descent();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void signForm(AForm &form);
		void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src);