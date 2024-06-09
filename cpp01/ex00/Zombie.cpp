#include "Zombie.hpp"

Zombie::Zombie(){
	_name = "default";
}

Zombie::~Zombie(){

}

void Zombie::announce(void)
{
	std::cout<<getName()<<": BraiiiiiiinnnzzzZ...";
}

std::string Zombie::getName(void) const { return this->_name; }
void        Zombie::setName(std::string name) { this->_name = name; }