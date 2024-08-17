#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->_idea = new Brain;
    std::cout << this->_type << " constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
    this->_idea = new Brain(*src._idea);
    return *this;
}

Cat::~Cat()
{
    delete this->_idea;
    std::cout << this->_type << " destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau" << std::endl;
}