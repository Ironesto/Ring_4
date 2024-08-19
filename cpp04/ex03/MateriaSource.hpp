#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_materia[4];

    public:
        MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};