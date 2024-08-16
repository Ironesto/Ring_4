#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout <<"Empty FragTrap constructor called" << std::endl << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->setName(name);
	this->setHealth(100);
	this->setEnergy(100);
	this->setDamage(30);
	std::cout <<"Filled FragTrap constructor called" << std::endl << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
    *this = src;
	std::cout <<"Copy FragTrap constructor called" << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	this->setName(src.getName());
	this->setHealth(src.getHealth());
	this->setEnergy(src.getEnergy());
	this->setDamage(src.getDamage());
    return *this;
}
FragTrap::~FragTrap()
{
	std::cout << std::endl << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "C´MON GUYS, GIVE ME FIVE" << std::endl;
}

