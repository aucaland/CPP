/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:16 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 17:05:48 by aurel            ###   ########.fr       */
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
	std::cout << "N: " << std::flush;
	std::cin >> N;
	Zombie *zombie = Zombie::zombieHorde(N, name);

	for (int i = 0; i < N; i++)
	{
		std::cout << zombie[i].index << ": " << std::flush;
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}