#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	newzom;
	newzom.setName(name);
	newzom.announce();
}
