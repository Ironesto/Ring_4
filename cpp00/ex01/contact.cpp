#include "contact.hpp"

Contact::Contact(){
	_name		= "default";
	_lstname	= "default";
	_nick		= "default";
	_number		= "default";
	_secret		= "default";
	//std::cout << "Constructor called" << std::endl;
}

Contact::~Contact(){
	//std::cout << "Destructor called" << std::endl;
}

std::string Contact::getName(void) const { return this->_name; }
void        Contact::setName(std::string name) { this->_name = name; }

std::string Contact::getLstName(void) const { return this->_lstname; }
void        Contact::setLstName(std::string lstname) { this->_lstname = lstname; }

std::string Contact::getNickname(void) const { return this->_nick; }
void        Contact::setNickname(std::string nick) { this->_nick = nick; }

std::string Contact::getNumber(void) const { return this->_number; }
void        Contact::setNumber(std::string number) { this->_number = number; }

std::string Contact::getSecret(void) const { return this->_secret; }
void        Contact::setSecret(std::string secret) { this->_secret = secret; }
