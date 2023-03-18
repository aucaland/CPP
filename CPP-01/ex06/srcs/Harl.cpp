/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:08:55 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 15:44:05 by aurel            ###   ########.fr       */
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
	string levels_array[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[])() = { &Harl::debug, &Harl::info,
								  &Harl::warning,
								  &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels_array[i] == level)
		{
			switch (i)
			{
				case 0:
					for (int j = 0; j < 4; j++)
						(this->*funcPtr[j])();
					break;
				case 1:
					for (int j = 1; j < 4; j++)
						(this->*funcPtr[j])();
					break;
				case 2:
					for (int j = 2; j < 4; j++)
						(this->*funcPtr[j])();
					break;
				case 3:
					(this->*funcPtr[3])();
					break;
				default:
					cout << "[ Probably complaining about insignificant "
							"problems ]" << endl;
			}
		}
	}
}

