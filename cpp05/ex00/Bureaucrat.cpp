#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("void") {}
Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {}
Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->_name; }
//void Bureaucrat::setName(std::string name) { this->_name = name; }
int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::GradeTooHighException(int grade)
{
    if (this->_grade < grade) throw
        std::runtime_error("grade too high");
}
void Bureaucrat::GradeTooLowException(int grade)
{
    if (this->_grade > grade) throw
        std::runtime_error("grade too low");
}

std::ofstream &operator<<(std::ofstream &o, const Bureaucrat &src)
{
    std::cout << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}
