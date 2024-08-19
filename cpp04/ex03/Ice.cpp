#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

// Ice::Ice(const Ice &src) : AMateria(src)
// {
//     //*this = src;
// }

// Ice &Ice::operator=(const Ice &src)
// {
//     this->_type = src._type;
//     return *this;
// }

Ice::~Ice()
{

}

Ice *Ice::clone() const
{
    Ice *aux = new Ice;
    return aux;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}