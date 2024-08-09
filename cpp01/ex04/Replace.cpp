#include "Replace.hpp"

Replace::Replace(std::string file)
{
	_infile = file;
	_outfile = file + ".replace";

}

Replace::~Replace()
{
	
}


int Replace::DoThings(std::string wan, std::string rep)
{
	std::ifstream	ifs(_infile.data());

	if (ifs.is_open() == 0)
		return (std::cerr<<"Error opening file"<<std::endl, 1);
	std::string content;
	std::ofstream	ofs(_outfile.data());
	std::getline(ifs, content, '\0');
	size_t	poswan = content.find(wan);

	ofs <<content.substr(0, poswan);
	while (poswan < content.length())
	{
		ofs <<rep;
		content = content.substr(poswan + wan.length(), content.length());
		poswan = content.find(wan);
		ofs << content.substr(0, poswan);
	}
	return 0;
}
