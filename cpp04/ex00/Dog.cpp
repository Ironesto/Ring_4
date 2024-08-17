#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << this->_type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << this->_type << " destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wof" << std::endl;
}