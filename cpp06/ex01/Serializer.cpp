#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &src) { *this = src; }
Serializer &Serializer::operator=(const Serializer &src) { *this = src; return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t s = 0;
	s = reinterpret_cast<uintptr_t>(ptr);
	return s;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *des;
	des = reinterpret_cast<Data*>(raw);
	// std::cout << "Str: " << des->str << std::endl;
	// std::cout << "Int: " << des->nbr << std::endl;
	// std::cout << "Char: " << des->c << std::endl;
	return des;
}
