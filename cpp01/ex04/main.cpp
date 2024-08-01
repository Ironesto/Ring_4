#include "Replace.hpp"

int main(int argc, char **argv)
{
	std::ifstream	ifs(argv[1]);
	std::string		name2 = ".replace";
	std::string		name = argv[1] + name2;
	std::string		rep;
	std::string		wan;
	std::ofstream	ofs(name.data());

	//ifs >> dst >> dst2;
	std::cout << name << std::endl;
	//std::cout << dst << " " << dst2 << std::endl;
	if (argc != 4)
		return (std::cerr<<"Error: bad aguments"<<std::endl , 1);
	if (ifs.is_open() == 0)
		return (std::cerr<<"Error opening file"<<std::endl, 1);
	return 0;
}
