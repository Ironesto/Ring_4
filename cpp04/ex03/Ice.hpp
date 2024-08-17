#include "AMateria.hpp"

class Ice : public AMateria
{
    protected:

    public:
        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &src);
        ~Ice();

        Ice *clone() const;
};