#include "Replace.hpp"

Replace::Replace(char *file, std::string wan, std::string rep)
{
	_file = file;
	_wan = wan;
	_rep = rep;
}

Replace::~Replace()
{
	
}


int Replace::DoThings(void)
{
	std::ifstream	ifs("file.txt");

	if (ifs.is_open() == 0)
		return (std::cerr<<"Error opening file"<<std::endl, 1);

	std::string		name2 = ".replace";
	std::string		name = _file + name2;
	std::string		content;
	std::ofstream	ofs(name.data());

	//ifs >> dst >> dst2;
	std::cout << name << std::endl;
	//std::cout << dst << " " << dst2 << std::endl;
	std::getline(ifs, content, '\0');
	std::cout<<content<<std::endl;
	// ofs << content;
	return 0;
}