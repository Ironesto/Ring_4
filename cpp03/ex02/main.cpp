#include "FragTrap.hpp"

int	main()
{
	FragTrap emptyfrag;
	FragTrap frag("Roberto");
	FragTrap copyfrag = frag;
	std::string target = "Jose Miguel";

	std::cout << "Select your FragTrap" << std::endl;
	std::cout << emptyfrag.getName() << " | " << frag.getName();
	std::cout << " | " << copyfrag.getName() << std::endl;
	std::cout << "You choose " << frag.getName() << std::endl;
	std::cout << "Its stats are:" << std::endl;
	std::cout << "Health " << frag.getHealth() << std::endl;
	std::cout << "Energy " << frag.getEnergy() << std::endl;
	std::cout << "Damage " << frag.getDamage() << std::endl << std::endl;
	frag.attack(target);
	frag.highFivesGuys();
    std::cout << "Perfect now " << target << " is angry" << std::endl;
    frag.takeDamage(30);
    std::cout << "FragTrap " << frag.getName() <<std::endl;
    std::cout << "Health " << frag.getHealth() <<std::endl;
    std::cout << "Energy " << frag.getEnergy() <<std::endl;
    std::cout << "Damage " << frag.getDamage() <<std::endl;
    frag.beRepaired(15);
    std::cout << "FragTrap " << frag.getName() <<std::endl;
    std::cout << "Health " << frag.getHealth() <<std::endl;
    std::cout << "Energy " << frag.getEnergy() <<std::endl;
    std::cout << "Damage " << frag.getDamage() <<std::endl;
    std::cout << "Better leave " << target << " alone" << std::endl;
	return 0;
}