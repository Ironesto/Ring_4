#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    this->_type = "Animal";
    std::cout << "AAnimal empty constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    this->_type = type;
    std::cout << "AAnimal filled constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
    *this = src;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    this->_type = src._type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

// void AAnimal::makeSound() const
// {
//     std::cout << "AAnimal make sound" << std::endl;
// }

std::string AAnimal::getType() const { return this->_type; }
void AAnimal::setType(std::string type) { this->_type = type; }