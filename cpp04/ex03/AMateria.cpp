#include "AMateria.hpp"

AMateria::AMateria()
{
    this->_type = "void";
}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    this->_type = src._type;
    return *this;
}

void AMateria::use(ICharacter& target)
{
    
}

std::string const &AMateria::getType() const { return this->_type; }