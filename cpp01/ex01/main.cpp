#include "Zombie.hpp"
#include <iostream>

int	main()
{
	int N = 3;
	Zombie *horde = zombieHorde(N, "Paco");
	for(int i = 0; i < N; i++)
	{
		std::cout<<"Zombie "<<i<<std::endl;
		horde[i].announce();
	}
	delete []horde;
	return (0);
}