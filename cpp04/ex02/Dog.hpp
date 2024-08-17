#pragma once

#include "AAnimal.hpp"

class Dog : public AAnimal
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