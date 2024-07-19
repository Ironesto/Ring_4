#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];
    if (N > 0 && N <= 2147483647)
    {
        for (int i = 0; i < N; i++)
            horde[i].setName(name);
        return horde;
    }
    else
        return NULL;
}