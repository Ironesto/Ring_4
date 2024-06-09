#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newzom;
	newzom->setName(name);
	return (newzom);
}