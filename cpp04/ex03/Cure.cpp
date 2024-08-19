#include "Cure.hpp"

Cure::Cure() : AMateria("cure") { }

Cure::~Cure() { }

Cure *Cure::clone() const
{
    Cure *aux = new Cure;
    return aux;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}