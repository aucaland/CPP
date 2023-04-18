/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:16 by aurel             #+#    #+#             */
/*   Updated: 2023/04/18 16:01:17 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

int main()
{
	string	name;
	int		N;

	std::cout << "Enter zombies number and the name:" << std::endl;
	std::cout << "name: " << std::flush;
	std::cin >> name;
	if (std::cin.eof() || std::cin.bad())
		std::exit(1);
	std::cout << "N: " << std::flush;
	if (std::cin.eof() || std::cin.bad())
		std::exit(1);

	if (!(std::cin >> N))
	{
		std::cout << "N has to be an int" << std::endl;
		std::exit(1);
	}
	Zombie *zombie = Zombie::zombieHorde(N, name);

	for (int i = 0; i < N; i++)
	{
		std::cout << zombie[i].getIndex() << ": " << std::flush;
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}