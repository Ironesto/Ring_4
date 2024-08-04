#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr<<"Error: bad aguments"<<std::endl , 1);
	Replace replace = Replace(argv[1], argv[2], argv[3]);
	replace.DoThings();
	return 0;
}
