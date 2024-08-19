#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::_debug( void )
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my ";
	std::cout<<"7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n"<<std::endl;
}

void Harl::_info( void )
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl;
	std::cout<<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"<<std::endl;
}

void Harl::_warning( void )
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout<<"I’ve been coming for years whereas you started working here since last month.\n"<<std::endl;
}
void Harl::_error( void )
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now.\n"<<std::endl;
}

void Harl::complain( std::string level )
{
	std::string	options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			num = 0;

	while (num < 4)
	{
		if (!level.compare(options[num]))
			break;
		num++;
	}
	switch (num)
	{
		case 0:
			this->_debug();
			this->_info();
			this->_warning();
			this->_error();
			break ;
		case 1:
			this->_info();
			this->_warning();
			this->_error();
			break ;
		case 2:
			this->_warning();
			this->_error();
			break ;
		case 3:
			this->_error();
			break ;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
	}
}
