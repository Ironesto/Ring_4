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

	Zombie*		newZombie( std::string name );
	void		randomChump( std::string name );