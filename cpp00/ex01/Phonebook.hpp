#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class	Contact;

class	Phonebook {

	private:
//		int		_index;
		Contact	_contact[8];

		int	add(int nlist);
		int	search();
		int	resultsearch();

	public:
		Phonebook();
		~Phonebook();

		int loop();

};

/* typedef struct s_contact
{
	std::string	name;
	std::string	lstname;
	std::string	nick;
	int *number;
	std::string secret;
} t_contact;

typedef struct s_book
{
	s_contact list[8];
} t_book; */
#endif