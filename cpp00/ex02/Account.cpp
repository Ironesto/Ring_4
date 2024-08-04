#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

int		Account::getNbAccounts(void) { return Account::_nbAccounts; }
int		Account::getTotalAmount(void) { return Account::_totalAmount; }
int		Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int		Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void	Account::displayAccountsInfos(void) 
{
	Account::_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount<<";deposits:";
	std::cout<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount - deposit<<";deposit:";
	std::cout<<deposit<<";amount:"<<_amount<<";nb_deposits:"<<_nbDeposits<<std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
		return 0;
	}
	Account::_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount + withdrawal<<";withdrawal:";
	std::cout<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
	return 1;
}

int		Account::checkAmount(void) const { return  _amount; }

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount;
	std::cout<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;

}	

void	Account::_displayTimestamp(void)
{
    std::time_t    timer = std::time(NULL);
    std::tm        *local_timer = std::localtime(&timer);
    char        timestamp[16];

    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", local_timer);
    std::cout << "[" << timestamp << "] ";
}
