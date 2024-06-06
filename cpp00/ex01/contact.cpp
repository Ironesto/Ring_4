#include "contact.hpp"

Contact::Contact(){
    _name = "default";
    std::cout << "Constructor called" << std::endl;
}

Contact::~Contact(){
    std::cout << "Destructor called" << std::endl;
}

std::string Contact::getName(void) const { return this->_name; }
void        Contact::setName(std::string name) { this->_name = name; }