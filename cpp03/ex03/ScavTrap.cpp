#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout <<"Empty ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout <<"Filled ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " <<this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is trying to enter in Gate keeper mode!" << std::endl;
}