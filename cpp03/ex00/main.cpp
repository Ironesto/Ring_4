#include "ClapTrap.hpp"

int main ()
{
    ClapTrap a("Juanito");
    std::string target = "Pepe";
    std::cout << "ClapTrap " << a.getName() <<std::endl;
    std::cout << "Health " << a.getHealth() <<std::endl;
    std::cout << "Energy " << a.getEnergy() <<std::endl;
    std::cout << "Damage " << a.getDamage() <<std::endl;
    a.attack(target);
    std::cout << "Perfect now " << target << " is angry" << std::endl;
    a.takeDamage(3);
    std::cout << "ClapTrap " << a.getName() <<std::endl;
    std::cout << "Health " << a.getHealth() <<std::endl;
    std::cout << "Energy " << a.getEnergy() <<std::endl;
    std::cout << "Damage " << a.getDamage() <<std::endl;
    a.beRepaired(2);
    std::cout << "ClapTrap " << a.getName() <<std::endl;
    std::cout << "Health " << a.getHealth() <<std::endl;
    std::cout << "Energy " << a.getEnergy() <<std::endl;
    std::cout << "Damage " << a.getDamage() <<std::endl;
    std::cout << "Better leave " << target << " alone" << std::endl;
    return 0;
}
