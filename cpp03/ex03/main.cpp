#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dia("juancho");

    dia.attack("Pepe");
    dia.guardGate();
    dia.highFivesGuys();
    std::cout << std::endl;
    dia.whoAmI();
    //std::cout << std::endl;

    // dia.setName("Ramón");
    // std::cout << dia.getName() << std::endl;
    // std::cout << dia.ClapTrap::getName() << std::endl;
    return 0;
}