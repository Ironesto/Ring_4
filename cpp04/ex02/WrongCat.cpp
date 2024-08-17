#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << this->_type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << this->_type << " destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Miau" << std::endl;
}