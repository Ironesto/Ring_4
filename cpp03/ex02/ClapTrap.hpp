#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		~ClapTrap();

		std::string	getName() const;
		void		setName(std::string name);
		int			getHealth() const;
		void		setHealth(int h);
		int			getEnergy() const;
		void		setEnergy(int e);
		int			getDamage() const;
		void		setDamage(int d);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
