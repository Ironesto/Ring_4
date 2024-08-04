#include <iostream>
#include <istream>
#include <fstream>
#include <string>

class Replace
{
	private:
		std::string	_file;
		std::string	_wan;
		std::string	_rep;
	public:
		Replace(char *file, std::string wan, std::string rep);
		~Replace();

		int DoThings(void);
};


