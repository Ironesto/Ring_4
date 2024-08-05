#pragma once
#include <iostream>
#include <fstream>

class Replace
{
	private:
		std::string	_infile;
		std::string	_outfile;

	public:
		Replace(std::string file);
		~Replace();

		int DoThings(std::string wan, std::string rep);
};


