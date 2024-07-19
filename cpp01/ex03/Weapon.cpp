#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    _type = type;
    std::cout<<"Constructor called for "<<_type<<std::endl;
}

Weapon::~Weapon(){
    std::cout<<"Destructor called for weapon "<<_type<<std::endl;
}

std::string         Weapon::getType(void) const { return this->_type; }
void                Weapon::setType(std::string type) { this->_type = type; }