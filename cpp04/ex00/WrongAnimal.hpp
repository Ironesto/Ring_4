#include <iostream>

class WrongAnimal
{
    protected:
    std::string _type;

    public:
        WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal &operator=(const WrongAnimal &src);
		~WrongAnimal();

        std::string getType() const;
		void setType(std::string type);
		void makeSound() const;
};