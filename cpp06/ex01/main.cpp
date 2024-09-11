#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data *target = new Data;
	Data *des = NULL;
	uintptr_t ser;
	
	target->str = "hola mundo";
	target->nbr = 42;
	target->c = 'c';
	std::cout << "Pre serialized" << std::endl;
	std::cout << "Str: " << target->str << std::endl;
	std::cout << "Int: " << target->nbr << std::endl;
	std::cout << "Char: " << target->c << std::endl;
	std::cout << "Memory dir: " << target << std::endl;
	ser = Serializer::serialize(target);
	des = Serializer::deserialize(ser);
	std::cout << "Post serialized" << std::endl;
	std::cout << "Str: " << des->str << std::endl;
	std::cout << "Int: " << des->nbr << std::endl;
	std::cout << "Char: " << des->c << std::endl;
	std::cout << "Memory dir: " << des << std::endl;
	delete target;
	return 0;
}