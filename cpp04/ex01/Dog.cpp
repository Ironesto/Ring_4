#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->_idea = new Brain;
    std::cout << this->_type << " constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
    this->_idea = src._idea;
    this->_idea = new Brain(*src._idea);
    return *this;
}

Dog::~Dog()
{
    delete this->_idea;
    std::cout << this->_type << " destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wof" << std::endl;
}