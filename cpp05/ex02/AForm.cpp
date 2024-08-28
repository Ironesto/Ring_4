#include "AForm.hpp"

AForm::AForm() : _name("Empty"), _gradsign(150), _gradexe(150)
{
	_signed = 0;
}

AForm::AForm(std::string name, int gradsign, int gradexe) : _name(name), _gradsign(gradsign), _gradexe(gradexe)
{
	this->_signed = 0;
	try
	{
		if (gradsign < 1)
			throw AForm::GradeTooHighException();
		else if (gradsign > 150)
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
AForm::AForm(const AForm &src) : _name(src._name), _gradsign(src._gradsign), _gradexe(src._gradexe)
{
	*this = src;
}

AForm &AForm::operator=(const AForm &src)
{
	this->_signed = src._signed;
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const		{ return this->_name; }
void		AForm::setSigned(bool i)	{ this->_signed = i; }
bool		AForm::getSigned() const		{ return this->_signed; }
int			AForm::getGradSign() const	{ return this->_gradsign; }
int			AForm::getGradExe() const	{ return this->_gradexe; }

bool AForm::beSigned(Bureaucrat bu)
{
	if (bu.getGrade() <= this->_gradsign && (this->_gradsign >= 1 && this->_gradsign <= 150))
		this->_signed = 1;
	else
		throw (AForm::GradeTooLowException());
	return 0;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("bureaucrat grade too high for this form");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("bureaucrat grade too low for this form");
}

std::ostream &operator<<(std::ostream &o, const AForm &src)
{
	o << "Name: " << src.getName() << std::endl;
	o << "Signed: " << src.getSigned() << std::endl;
	o << "Grade for sign: " << src.getGradSign() << std::endl;
	o << "Grade for execute: " << src.getGradExe() << std::endl;
	return o;
}

void AForm::beExec() const {}

bool AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == 0)
		throw std::string("This form is not signed");
	else if (this->_gradexe < executor.getGrade())
		throw std::string(executor.getName() + " can´t execute " + this->_name);
	return true;
}
