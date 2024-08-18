#include "Character.hpp"

Character::Character()
{
    _name = "default";
}

Character::Character(std::string name)
{
    _name = name;
}

Character::Character(const Character &src)
{
    *this = src;
}

Character &Character::operator=(const Character &src)
{
    this->_name = src._name;
    return *this;
}

Character::~Character() {}

std::string const &Character::getName() const { return this->_name; }