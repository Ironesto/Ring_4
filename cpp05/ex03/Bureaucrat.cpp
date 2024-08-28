#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("void") { this->_grade = 150; }
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		this->_grade = 1;
		std::cout << "Grade set as 1" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		this->_grade = 150;
		std::cout << "Grade set as 150" << std::endl;
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name) { *this = src; }
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }
void Bureaucrat::ascent()
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}


void Bureaucrat::descent()
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Bureaucrat grade  too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Bureaucrat grade  too low");
}

void Bureaucrat::signForm(AForm &form)
{
	if (this->_grade <= form.getGradSign()  && (form.getGradSign() >= 1 && form.getGradSign() <= 150))
	{
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
		return ;
	}
	std::cout << this->_name <<" couldn’t sign " << form.getName() << " because ";
	form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return o;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.execute(*this) == true)
	{
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		form.beExec();
	}
}