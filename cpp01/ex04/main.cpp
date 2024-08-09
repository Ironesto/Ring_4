#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr<<"Error: bad aguments"<<std::endl , 1);
	if (argv[1][0] == '\0')
		return (std::cerr<<"Error: wanted must exist"<<std::endl , 1);
	Replace replace = Replace(argv[1]);
	replace.DoThings(argv[2], argv[3]);
	return 0;
}
