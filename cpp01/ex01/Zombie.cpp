#include "Zombie.hpp"

Zombie::Zombie(){
	_name = "default";
	std::cout << "Constructor called"<<std::endl;
}

Zombie::~Zombie(){
	std::cout << "Destructor called for " <<_name<<std::endl;
}

void Zombie::announce(void)
{
	std::cout<<getName()<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

std::string Zombie::getName(void) const { return this->_name; }
void        Zombie::setName(std::string name) { this->_name = name; }