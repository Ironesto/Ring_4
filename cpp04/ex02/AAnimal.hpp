#pragma once

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		virtual ~AAnimal();

		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const = 0;
};