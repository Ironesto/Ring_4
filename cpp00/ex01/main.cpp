#include "Phonebook.hpp"



int main(int argc, char ** argv)
{
	Phonebook pbook;
	//int	num;
	if (argc != 1 || argv[1]) //para que no de el coñazo
	{
		std::cout<<"Too many arguments"<<std::endl;
		return 1;
	}
	std::cout<<"WELCOME TO YOUR PHONEBOOK\n";
	pbook.loop();
	//int list = 0;
/* 	while (list < 8)
	{
		std::cout<<"NUMERO "<<list<<std::endl;
		std::cout<<"name es "<<book.list[list].name<<std::endl;
		std::cout<<"last name es "<<book.list[list].lstname<<std::endl;
		std::cout<<"nickname es "<<book.list[list].nick<<std::endl;
		std::cout<<"numero "<<book.list[list].number<<std::endl;
		std::cout<<"secreto es "<<book.list[list].secret<<std::endl;
		list++;
	} */

	return (0);
}
