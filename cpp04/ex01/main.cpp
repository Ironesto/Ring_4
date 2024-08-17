#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        int numtot = 4;
            const Animal *granja[numtot];
        for (int i = 0; i < numtot / 2; i++)
            granja[i] = new Dog;
        for (int i = numtot / 2; i < numtot; i++)
            granja[i] = new Cat;
        std::cout << std::endl;
        while (numtot > 0)
        {
            delete granja[numtot - 1];
            numtot--;
        }
    }
    std::cout << std::endl << "Fin del primero" << std::endl;
    {
        std::cout << std::endl;
        Cat gato1;
        Cat gato2;
        gato1 = gato2;
    }
    return 0;
}