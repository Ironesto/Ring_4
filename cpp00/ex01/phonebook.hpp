#include <iostream>
#include <iomanip>
#include "contact.hpp"

class Contact;

class Phonebook {

    private:
        int _index;
        Contact _contact[8];

    public:
        Phonebook();
        ~Phonebook();

        int	search(t_book *book);

};

typedef struct s_contact
{
    std::string name;
    std::string lstname;
    std::string nick;
    int *number;
    std::string secret;
} t_contact;

typedef struct s_book
{
    s_contact list[8];
} t_book;