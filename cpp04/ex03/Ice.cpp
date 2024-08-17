#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{

}

Ice::Ice(const Ice &src) : AMateria(src)
{
    *this = src;
}

Ice &Ice::operator=(const Ice &src)
{
    this->_type = src._type;
    return *this;
}

Ice::~Ice()
{

}

Ice *Ice::clone() const
{
    *this = new Ice;
}