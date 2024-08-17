#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "WrongAnimal";
    std::cout << "WrongAnimal empty constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->_type = type;
    std::cout << "WrongAnimal filled constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    this->_type = src._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong WrongAnimal make sound" << std::endl;
}

std::string WrongAnimal::getType() const { return this->_type; }
void WrongAnimal::setType(std::string type) { this->_type = type; }