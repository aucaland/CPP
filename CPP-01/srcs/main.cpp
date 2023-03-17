/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:16 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 14:25:39 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"

int main()
{
	string	name;

	std::cout << "Create Zombie on the heap , enter his name: " << std::flush;
	std::cin >> name;

	Zombie *heapZombie = Zombie::newZombie(name);
	heapZombie->announce();
	delete heapZombie;
	return (0);
}