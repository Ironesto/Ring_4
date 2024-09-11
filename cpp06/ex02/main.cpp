#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	std::srand (std::time(0));
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else if (i == 2)
		return (new C);
	else
		std::cout << "Something went wrong. i is " << i << std::endl;
	return (new Base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base& p)
{
	Base bas;
	try
	{
		bas = dynamic_cast<A&>(p);
		std::cout << "A&" << std::endl;
	} catch (std::exception &e) {}
	try
	{
		bas = dynamic_cast<B&>(p);
		std::cout << "B&" << std::endl;
	} catch (std::exception &e) {}
	try
	{
		bas = dynamic_cast<C&>(p);
		std::cout << "C&" << std::endl;
	} catch (std::exception &e) {}
	//std::cout << p << std::endl;
}

int main()
{
	Base *random = NULL;
	random = generate();
	identify (random);
	identify(*random);
	if (random != NULL)
		delete random;
	return 0;
}