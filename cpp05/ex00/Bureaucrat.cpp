#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("void") {}
Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }
Bureaucrat &Bureaucrat::operator=(conts Bureaucrat &src)
