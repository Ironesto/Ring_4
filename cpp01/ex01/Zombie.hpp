#pragma once
#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void announce(void);

		std::string	getName() const;
		void		setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );
