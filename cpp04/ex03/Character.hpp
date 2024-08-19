#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria    *_slot[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character &src);
        Character &operator=(const Character &src);
        ~Character();

        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
