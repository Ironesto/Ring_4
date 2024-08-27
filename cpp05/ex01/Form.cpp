#include "Form.hpp"

Form::Form() : _name("Empty"), _gradsign(150), _gradexe(150)
{
	_signed = 0;
}

Form::Form(std::string name, int gradsign) : _name(name), _gradsign(gradsign), _gradexe(150)
{
	this->_signed = 0;
	try
	{
		if (gradsign < 1)
			throw Form::GradeTooHighException();
		else if (gradsign > 150)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
Form::Form(const Form &src) : _name(src._name), _gradsign(src._gradsign), _gradexe(src._gradexe)
{
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	this->_signed = src._signed;
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const		{ return this->_name; }
bool		Form::getSigned() const		{ return this->_signed; }
int			Form::getGradSign() const	{ return this->_gradsign; }
int			Form::getGradExe() const	{ return this->_gradexe; }

bool Form::beSigned(Bureaucrat bu)
{
	if (bu.getGrade() <= this->_gradsign && (this->_gradsign >= 1 && this->_gradsign <= 150))
		this->_signed = 1;
	else
		throw (Form::GradeTooLowException());
	return 0;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("form grade too low");
}

std::ostream &operator<<(std::ostream &o, const Form &src)
{
	o << "Name: " << src.getName() << std::endl;
	o << "Signed: " << src.getSigned() << std::endl;
	o << "Grade for sign: " << src.getGradSign() << std::endl;
	o << "Grade for execute: " << src.getGradExe() << std::endl;
	return o;
}