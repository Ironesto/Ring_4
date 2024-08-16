#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout <<"Empty ScavTrap constructor called" << std::endl << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setName(name);
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout <<"Filled ScavTrap constructor called" << std::endl << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout <<"Copy ScavTrap constructor called" << std::endl << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " <<this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	this->setName(src.getName());
	this->setHealth(src.getHealth());
	this->setEnergy(src.getEnergy());
	this->setDamage(src.getDamage());
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is trying to enter in Gate keeper mode!" << std::endl;
}