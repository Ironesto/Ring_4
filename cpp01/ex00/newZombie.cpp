#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newzom = new Zombie;
	newzom->setName(name);
	return (newzom);
}