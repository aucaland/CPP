/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:50:55 by aurel             #+#    #+#             */
/*   Updated: 2023/04/18 16:28:08 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Harl.h"

int main()
{
	string	level;
	Harl	harl;

	while (level != "EXIT")
	{
		cout << "Enter a level: [DEBUG] [INFO] [WARNING] [ERROR] : " << std::flush;
		std::getline(std::cin, level);
		if (std::cin.eof() || std::cin.fail())
			std::exit(1);
		if (level.empty() || !std::cin.good() || level[0] == '\n')
			continue ;
		harl.complain(level);
	}
	return (0);
}