#ifndef CONTACT_HPP
 #define CONTACT_HPP
#include <iostream>

class Contact {

	private:
		std::string	_name;
		std::string	_lstname;
		std::string	_nick;
		std::string	_number;
		std::string	_secret;

	public:
		Contact();
		~Contact();

		std::string	getName() const;
		void		setName(std::string name);

		std::string	getLstName() const;
		void		setLstName(std::string lstname);

		std::string	getNickname() const;
		void		setNickname(std::string nick);

		std::string	getNumber() const;
		void		setNumber(std::string number);
		
		std::string	getSecret() const;
		void		setSecret(std::string secret);
};

#endif