/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:08:55 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 15:23:43 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.h"


Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::debug()
{
	cout << "DEBUG" << endl;
}

void	Harl::info()
{
	cout << "INFO" << endl;
}

void	Harl::warning()
{
	cout << "WARNING" << endl;
}

void	Harl::error()
{
	cout << "ERROR" << endl;
}

void	Harl::complain(std::string level)
{
	string levels_array[] = { "WARNING", "ERROR", "INFO", "DEBUG"};
	void (Harl::*funcPtr[])() = { &Harl::warning, &Harl::error,
									  &Harl::info,
									  &Harl::debug};
	for (int i = 0; i < 4; i++)
	{
		if (levels_array[i] == level)
			(this->*funcPtr[i])();
	}
}

