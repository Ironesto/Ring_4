#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout <<"Empty FragTrap constructor called" << std::endl << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout <<"Filled FragTrap constructor called" << std::endl << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << std::endl << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "C´MON GUYS, GIVE ME FIVE" << std::endl;
}

