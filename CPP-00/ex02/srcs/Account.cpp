/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:50:39 by aurel             #+#    #+#             */
/*   Updated: 2023/03/16 12:45:46 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/Account.hpp"
#include <ctime>
#include <iostream>


Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

void	Account::_displayTimestamp()
{
	std::time_t t = std::time(NULL);
	std::tm tm = *std::localtime(&t);
	char timestamp[20];

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", &tm);
	std::cout << timestamp << " " << std::flush;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

int 	Account::checkAmount() const
{
	return _amount;
}

void 	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "deposit:" << deposit << ";" << std::flush;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

void 	Account::_displayRefusedWithdrawal() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "withdrawal:refused" << std::endl;
}

bool 	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > checkAmount())
	{
		_displayRefusedWithdrawal();
		return false;
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:" << withdrawal << ";" << std::flush;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

void 	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}


