#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("void") { this->_grade = 150; }
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) { this->_grade = grade; }
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
	return ("Error: Grade  too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade  too low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return o;
}
