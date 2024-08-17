#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << this->_type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << this->_type << " destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau" << std::endl;
}