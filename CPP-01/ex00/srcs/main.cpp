/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:16 by aurel             #+#    #+#             */
/*   Updated: 2023/04/18 15:44:11 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

int main()
{
	string	name;

	std::cout << "Create Zombie on the heap , enter his name: " << std::flush;
	std::cin >> name;
	std::cin.clear();
	Zombie *heapZombie = Zombie::newZombie(name);
	heapZombie->announce();

	std::cout << "Create Zombie on the stack , enter his name: " << std::flush;
	std::cin >> name;
	std::cin.clear();
	Zombie stackZombie(name);
	stackZombie.announce();

	std::cout << "Create a random Zombie: " << std::endl;
	Zombie::randomChump("random");

	delete heapZombie;
	return (0);
}