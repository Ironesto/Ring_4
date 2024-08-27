#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradsign;
		const int _gradexe;

	public:
		Form();
		Form(std::string name, int gradsign);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradSign() const;
		int getGradExe() const;

		bool beSigned(Bureaucrat bu);
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
};

std::ostream &operator<<(std::ostream &o, const Form &src);
