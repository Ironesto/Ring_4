#include <iostream>
#include <fstream>
#include <string>

class Replace
{
	private:
		std::string	_file;
		std::string	_wan;
		std::string	_rep;
	public:
		Replace(char *file, char *wan, char *rep);
		~Replace();
};


