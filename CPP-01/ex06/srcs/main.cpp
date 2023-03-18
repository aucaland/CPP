/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:50:55 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 15:11:51 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.h"

int main()
{
	string	level;
	Harl	harl;

	while (level != "EXIT")
	{
		cout << "Enter a level: " << std::flush;
		std::getline(std::cin, level);
		if (level.empty() || !std::cin.good() || level[0] == '\n')
			continue ;
		harl.complain(level);
	}
	return (0);
}