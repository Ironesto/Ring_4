#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->_name = name;
    this->_weapon = NULL;
    std::cout<<"Constructor called for HumanB "<<_name<<std::endl;
}

HumanB::~HumanB(){
    std::cout<<"Destructor called for HumanB "<<_name<<std::endl;
}

void HumanB::attack() {
    if (_weapon == NULL)
        std::cout<<_name<<" doesnt have a weapon, he attacks with his fist"<<std::endl;
    else
        std::cout<<_name<<" attacks with their "<<_weapon->getType()<<std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon;}

