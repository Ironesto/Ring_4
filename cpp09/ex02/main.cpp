#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	// int i = 0;
	// while (i < argc)
	// {
	// 	std::cout << "[" << i <<"] " << argv[i] << ", ";
	// 	i++;
	// }
	try {
		PMerge::DoThings(argc, argv);
	}
	catch(std::string &e)
	{
		std::cout << e << std::endl; 
	}
	return 0;
}