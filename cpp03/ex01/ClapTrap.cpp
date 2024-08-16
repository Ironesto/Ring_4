#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "default";
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout <<"Empty ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout <<"Filled ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout <<"Copy ClapTrap constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	_name = src._name;
	//por que se puede esto y no es con getName()?
	_health = src._health;
	_energy = src._energy;
	_damage = src._damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " <<this->_name << " attacks " << target << ", causing ";
	std::cout << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " <<this->_name << " has received " << amount << " points of damage!" << std::endl;
	this->_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " <<this->_name << " has repaired " << amount << " points of health!" << std::endl;
	this->_health += amount;
	this->_energy--;
}

std::string ClapTrap::getName() const { return this->_name; }
void ClapTrap::setName(std::string name) { this->_name = name; }
int ClapTrap::getHealth() const { return this->_health; }
void ClapTrap::setHealth(int h) { this->_health = h; }
int ClapTrap::getEnergy() const { return this->_energy; }
void ClapTrap::setEnergy(int e) { this->_energy = e; }
int ClapTrap::getDamage() const { return this->_damage; }
void ClapTrap::setDamage(int d) { this->_damage = d; }
