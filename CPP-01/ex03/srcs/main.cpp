/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:49:40 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 19:36:11 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../incs/Weapon.h"
#include "../incs/HumanB.h"
#include "../incs/HumanA.h"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{

		HumanB jim("Jim");

		jim.attack();
		Weapon club = Weapon("long bow");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}