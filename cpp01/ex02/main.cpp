#include <iostream>

int	main()
{
	std::string brain = "HI THIS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout<<"string memory "<<&brain<<std::endl;
	std::cout<<"Pointer memory "<<stringPTR<<std::endl;
	std::cout<<"Reference memory "<<&stringREF<<std::endl;
	std::cout<<std::endl;
	std::cout<<"string value "<<brain<<std::endl;
	std::cout<<"Pointer value "<<*stringPTR<<std::endl;
	std::cout<<"Reference value "<<stringREF<<std::endl;
	return 0;
}