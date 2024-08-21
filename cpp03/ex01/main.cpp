#include "ScavTrap.hpp"

int	main()
{
	ScavTrap emptyscav;
	ScavTrap scav("Maria");
	ScavTrap copyscav = scav;
	std::string target = "Jose Miguel";

	std::cout << "Select your ScavTrap" << std::endl;
	std::cout << emptyscav.getName() << " | " << scav.getName();
	std::cout << " | " << copyscav.getName() << std::endl;
	std::cout << "You choose " << scav.getName() << std::endl;
	std::cout << "Its stats are:" << std::endl;
	std::cout << "Health " << scav.getHealth() << std::endl;
	std::cout << "Energy " << scav.getEnergy() << std::endl;
	std::cout << "Damage " << scav.getDamage() << std::endl << std::endl;
	scav.attack(target);
    std::cout << "Perfect now " << target << " is angry" << std::endl;
    scav.takeDamage(30);
	scav.guardGate();
    std::cout << "ScavTrap " << scav.getName() <<std::endl;
    std::cout << "Health " << scav.getHealth() <<std::endl;
    std::cout << "Energy " << scav.getEnergy() <<std::endl;
    std::cout << "Damage " << scav.getDamage() <<std::endl;
    scav.beRepaired(15);
    std::cout << "ScavTrap " << scav.getName() <<std::endl;
    std::cout << "Health " << scav.getHealth() <<std::endl;
    std::cout << "Energy " << scav.getEnergy() <<std::endl;
    std::cout << "Damage " << scav.getDamage() <<std::endl;
    std::cout << "Better leave " << target << " alone" << std::endl;
	return 0;
}