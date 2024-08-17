#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout <<"Empty FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout <<"Filled FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << std::endl << "FragTrap destructor called";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "C´MON GUYS, GIVE ME FIVE" << std::endl;
}

