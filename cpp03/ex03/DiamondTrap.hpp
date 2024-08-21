#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        ~DiamondTrap();
        void whoAmI();

        //std::string getName() const { return this->_name; }
        //void setName(std::string name) { this->_name = name; }
};