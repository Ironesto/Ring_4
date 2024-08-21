#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    while (i < 4)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = m;
            std::cout << m->getType() << " learned in slot " << i << std::endl;
            break ;
        }
        i++;
    }
    if (i == 4)
        std::cout << "Memory full" << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    std::cout << "That´s not a learned materia" << std::endl;
    return NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) { *this = src; }

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._materia[i] == NULL)
            this->_materia[i] = NULL;
        this->_materia[i] = src._materia[i];
    }
    return *this;
}

MateriaSource::~MateriaSource() {}
