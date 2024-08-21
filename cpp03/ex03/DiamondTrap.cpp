#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout <<"Empty DiamondTrap constructor called" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
	std::cout <<"Filled DiamondTrap constructor called" << std::endl << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << std::endl << "DiamondTrap destructor called";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
}
