#include "Brain.hpp"

Brain::Brain()
{
    *this->_ideas = "default";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
    *this = src;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    *this->_ideas = *src._ideas;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}