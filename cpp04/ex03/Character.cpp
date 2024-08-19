#include "Character.hpp"

Character::Character()
{
    _name = "default";
    for (int i = 0; i < 4; i++)
        this->_slot[i] = NULL;
}

Character::Character(std::string name)
{
    _name = name;
    for (int i = 0; i < 4; i++)
        this->_slot[i] = NULL;
}

Character::Character(const Character &src)
{
    *this = src;
}

Character &Character::operator=(const Character &src)
{
    this->_name = src._name;
    for (int i = 0; i < 4; i++)
        delete this->_slot[i];
    for (int i = 0; i < 4; i++)
        this->_slot[i] = src._slot[i]->clone();
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->_slot[i];
}

void Character::equip(AMateria* m)
{
    int i = 0;
    while (i < 4)
    {
        if (this->_slot[i] == NULL)
        {
            this->_slot[i] = m;
            std::cout << m->getType() << " equipped" << std::endl;
            break ;
        }
        i++;
    }
    if (i == 4)
        std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 4)
    {
        if (this->_slot[idx] != NULL)
        {
            delete this->_slot[idx];
            this->_slot[idx] = NULL;
            std::cout << "slot unequipped" << std::endl;
        }
        else
            std::cout << "This slot is already empty" << std::endl;
    }
    else
        std::cout << "That´s not a slot" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx < 4) && _slot[idx] != NULL)
        this->_slot[idx]->use(target);
    else
        std::cout << "Havent a material in slot " << idx << std::endl;
}

std::string const &Character::getName() const { return this->_name; }