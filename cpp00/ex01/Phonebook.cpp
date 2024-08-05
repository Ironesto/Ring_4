#include "Phonebook.hpp"

Phonebook::Phonebook() {

}

Phonebook::~Phonebook() {
	//std::cout << "Destructor called" << std::endl;
}

int	Phonebook::search()
{
	int	i = 0;
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"|  index   |";
	std::cout<<"first name|";
	std::cout<<"last name |";
	std::cout<<" nickname |"<<std::endl;
	//std::cout<<book->list[0].name;
	std::cout<<"---------------------------------------------"<<std::endl;
	while (i < 8)
	{
		std::cout<<"|"<<std::setw(5)<<i + 1<<std::setw(6)<<"|";
		if (_contact[i].getName().size() > 10)
		{
			std::string aux =  _contact[i].getName().substr(0, 10);
			aux[9] = '.';
			std::cout<<aux<<"|";
		}
		else
			std::cout<<_contact[i].getName()<<std::setw(11 - _contact[i].getName().length())<<"|";
		if (_contact[i].getLstName().size() > 10)
		{
			std::string aux =  _contact[i].getLstName().substr(0, 10);
			aux[9] = '.';
			std::cout<<aux<<"|";
		}
		else
			std::cout<<_contact[i].getLstName()<<std::setw(11 - _contact[i].getLstName().length())<<"|";
		if (_contact[i].getNickname().size() > 10)
		{
			std::string aux =  _contact[i].getNickname().substr(0, 10);
			aux[9] = '.';
			std::cout<<aux<<"|"<<std::endl;
		}
		else
			std::cout<<_contact[i].getNickname()<<std::setw(11 - _contact[i].getNickname().length())<<"|"<<std::endl;
		i++;
	}
	std::cout<<"---------------------------------------------"<<std::endl;
	resultsearch();
	return (0);
}

int Phonebook::resultsearch()
{
	std::cout<<"Which one do you want to see?"<<std::endl;
	std::string str;
	std::getline(std::cin, str);
	int i;

	i = 0;
	while(i < (int)str.length())
	{
		if (!std::isdigit(str[0]))
		{
			std::cout<<"Only numbers are accepted"<<std::endl;
			return (resultsearch());
		}
		i++;
	}
	i = atoi(str.data()) - 1;
	if (i == -1)
		return (0);
	if (i < 0 || i >= 8)
	{
		std::cout<<"Invalid number try again(0 to exit)"<<std::endl;
		std::getline(std::cin, str);
			i = 0;
		while(i < (int)str.length())
		{
			if (!std::isdigit(str[0]))
			{
				std::cout<<"Only numbers are accepted"<<std::endl;
				return (resultsearch());
			}
			i++;
		}
		i = atoi(str.data()) - 1;
		if (i == -1)
			return (0);
		else
			return resultsearch();
	}
	std::cout<<"Number: "<<i + 1<<std::endl;
	std::cout<<"His name: "<<_contact[i].getName()<<std::endl;
	std::cout<<"His  last name: "<<_contact[i].getLstName()<<std::endl;
	std::cout<<"His nickname: "<<_contact[i].getNickname()<<std::endl;
	std::cout<<"His number: "<<_contact[i].getNumber()<<std::endl;
	std::cout<<"His darkest secret: "<<_contact[i].getSecret()<<std::endl;
	return (0);
}

int	Phonebook::add(int nlist)
{
	std::string name;
	std::string lstname;
	std::string nick;
	std::string number;
	std::string secret;
	std::cout<<"\nAdding\n";
	std::cout<<"Please, enter the first name\n";
	std::getline(std::cin, name);
	if (name[0] == '\0')
		return 1;
	std::cout<<"Please, enter the last name\n";
	std::getline(std::cin, lstname);
	if (lstname[0] == '\0')
		return 1;
	std::cout<<"Please, enter the nickname\n";
	std::getline(std::cin, nick);
	if (nick[0] == '\0')
		return 1;
	std::cout<<"Please, enter the number\n";
	std::getline(std::cin, number);
	if (number[0] == '\0')
		return 1;
	std::cout<<"Please, enter the secret\n";
	std::getline(std::cin, secret);
	if (secret[0] == '\0')
		return 1;
	_contact[nlist].setName(name);
	_contact[nlist].setLstName(lstname);
	_contact[nlist].setNickname(nick);
	_contact[nlist].setNumber(number);
	_contact[nlist].setSecret(secret);
	return (0);
}

int Phonebook::loop()
{
	std::string	command;
	int		nlist = 0;
	int		aux;

	while (1)
	{
		aux = -1;
		if (nlist >= 8)
			nlist = -0;
		std::cout<<"What do you want to do?\n";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			if (add(nlist) == 0)
				nlist++;
			else
				std::cout<<"Invalid empty fields"<<std::endl;
		}
		if (!command.compare("SEARCH"))
			search();
		if (!command.compare("EXIT"))
			return (0);
	}
	return (1);
}
