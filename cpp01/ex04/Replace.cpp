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

	//ifs >> dst >> dst2;
	//std::cout << _outfile << std::endl;
	//std::cout << dst << " " << dst2 << std::endl;
	std::getline(ifs, content, '\0');
/* 	while (content != ifs.end())
	{
		size_t	pos = content.find(wan);
		if (pos != std::string::npos)


		std::getline(ifs, content, '\0');
	} */
/* 	for (size_t i = 0; i < content.length(); i++)
	{
		for (size_t k = 0; content[i] == wan[k]; k++)
		{

		}
	} */
	std::cout<<content<<std::endl;
	ofs << content;
	return 0;
}