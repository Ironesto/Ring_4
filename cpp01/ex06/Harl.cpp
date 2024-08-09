#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::_debug( void )
{
	std::cout<<"I love having extra bacon for my ";
	std::cout<<"7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"<<std::endl;
}

void Harl::_info( void )
{
	std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl;
	std::cout<<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::_warning( void )
{
	std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl;
	std::cout<<"I’ve been coming for years whereas you started working here since last month."<<std::endl;
}
void Harl::_error( void )
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain( std::string level )
{
	t_func		function[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			num = 0;

	while (num < 4)
	{
		if (!level.compare(options[num]))
		{
			(this->*function[num])();
			break;
		}
		num++;
	}
	if (num == 4)
		std::cout<<"Invalid option"<<std::endl;
}
