#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon){
    _name = name;
    std::cout<<"Constructor called for HumanA "<<_name<<std::endl;
}

HumanA::~HumanA() {
    std::cout<<"Destructor called for HumanA "<<_name<<std::endl;
}

void HumanA::attack() {
    std::cout<<_name<<" attacks with their "<<_weapon.getType()<<std::endl;
}
