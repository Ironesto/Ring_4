#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain *_idea;

    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        ~Dog();
        void makeSound() const;
};