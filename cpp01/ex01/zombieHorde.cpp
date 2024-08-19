#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N > 0 && N <= 2147483647)
    {
        Zombie *horde = new Zombie[N];
        for (int i = 0; i < N; i++)
            horde[i].setName(name);
        return horde;
    }
    else
        return NULL;
}