#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    protected:

    public:
        Cure();
        ~Cure();

        Cure *clone() const;
        void use(ICharacter& target);
};
