#pragma once

#include "Animal.hpp"

class Cat : public Animal
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