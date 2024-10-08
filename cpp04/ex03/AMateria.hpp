#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        AMateria &operator=(const AMateria &src);

    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &src);
        virtual ~AMateria();
        //[...]
        std::string const &getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
