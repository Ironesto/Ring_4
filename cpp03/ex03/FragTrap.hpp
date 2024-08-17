#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:

    public:
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap &src);
        FragTrap &operator=(const FragTrap &src);
        ~FragTrap();

        void highFivesGuys(void);
};