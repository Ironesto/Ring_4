#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr<<"Error: bad aguments"<<std::endl , 1);
	Replace replace = Replace(argv[1]);
	replace.DoThings(argv[2], argv[3]);
	return 0;
}
