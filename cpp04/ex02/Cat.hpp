#pragma once

#include "AAnimal.hpp"

class Cat : public AAnimal
{
    private:
        Brain *_idea;

    public:
        Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &src);
        ~Cat();
        void makeSound() const;
};