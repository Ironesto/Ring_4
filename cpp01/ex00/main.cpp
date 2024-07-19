#include "Zombie.hpp"

int	main()
{
	Zombie	*Paco = newZombie("Paco");
	Paco->announce();
	randomChump("Foo");
	delete Paco;
	return (0);
}