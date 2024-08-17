#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "Animal";
    std::cout << "Animal empty constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    this->_type = type;
    std::cout << "Animal filled constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    this->_type = src._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal make sound" << std::endl;
}

std::string Animal::getType() const { return this->_type; }
void Animal::setType(std::string type) { this->_type = type; }