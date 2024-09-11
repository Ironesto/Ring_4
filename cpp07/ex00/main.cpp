#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	int e = 10;
	std::cout << "min( a, e ) = " << ::min( a, e ) << std::endl;
	std::cout << "min( a, e ) = " << ::max( a, e ) << std::endl;
	std::cout << std::endl;
	std::string f = "chaine42";
	std::cout << "c = " << c << ", f = " << f << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, f ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, f ) << std::endl;
	return 0;
}