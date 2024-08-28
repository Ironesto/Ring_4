#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradsign;
		const int _gradexe;

	public:
		AForm();
		AForm(std::string name, int gradsign, int gradexe);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		void setSigned(bool i);
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
		virtual void beExec() const;
		bool execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &src);
