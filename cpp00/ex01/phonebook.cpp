#include "phonebook.hpp"
#include <stdio.h>
#include <cstring>

int	Phonebook::search(t_book *book)
{
	int	i = 0;
	std::cout<<"|  index   |";
	std::cout<<"first name|";
	std::cout<<"last name |";
	std::cout<<"nickname  |"<<std::endl;
	//std::cout<<book->list[0].name;
	while (i < 8)
	{
		std::cout<<"|"<<std::setw(5)<<i + 1<<std::setw(6)<<"|";
		if (book->list[i].name.size() > 10)
		{
			book->list[i].name.resize(10);
			book->list[i].name[9] = '.';
		}
		else

		std::cout<<book->list[i].name<<"|"<<std::endl;
		i++;
	}
	return (0);
}

int	add(t_contact *test)
{
	char command[40];
	std::cout<<"\nAdding\n";
	std::cout<<"Please, enter the first name\n";
	scanf("%s", command);
	test->name.assign(command);
	std::cout<<"Please, enter the last name\n";
	scanf("%s", command);
	test->lstname.assign(command);
	std::cout<<"Please, enter the nickname\n";
	scanf("%s", command);
	test->nick.assign(command);
	//std::cout<<"Please, enter the number\n";
	//scanf("%d", test->number);	//falla?
	//test.number.assign(num);
	std::cout<<"Please, enter the secret\n";
	scanf("%s", command);
	test->secret.assign(command);
	return (0);
}

int loop(t_book *book)
{
	char	command[40];
	Phonebook pbook;
	int		nlist = 0;
	int		aux;
	while (1)
	{
		aux = -1;
		if (nlist >= 8)
			nlist = 0;
		std::cout<<"What do you want to do?\n";
		scanf("%s", command);
		while (command[++aux])	//poner el comando en mayuscula para comodidad
			command[aux] = toupper(command[aux]);
		//std::cout<<command<<std::endl;
		if (!strcmp(command, "ADD"))
		{
			add(&book->list[nlist]);
			nlist++;
		}
		if (!strcmp(command, "SEARCH"))
			pbook.search(book);
		if (!strcmp(command, "EXIT"))
			return (0);
	}
	return (1);
}

int main(int argc, char ** argv)
{
	t_book	book;
	t_contact test;
	//int	num;
	if (argv[0] && argc == 0) //para que no de el coñazo
			std::cout<<"sueltame el brazo";
	std::cout<<"WELCOME TO YOUR PHONEBOOK\n";
	loop(&book);
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
