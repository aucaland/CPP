/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/20 23:13:59 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.h"

int main()
{
	// Virtual purpose
//	ClapTrap* test = new FragTrap("toto");
//	test->attack("truc");
//	delete test;
	DiamondTrap scavOne( "Macron" );
	DiamondTrap scavThree( "Benne a ordures");
	DiamondTrap scavTwo(scavThree);
	DiamondTrap test;

	test = scavTwo;
	scavOne.attack( "La ZAD de Notre Dame des Landes");
	scavOne.attack( " les retraites");
	scavTwo.attack( "Darmanin");
	scavThree.attack( "la Macronie");
	test.attack("dans le vent");
	scavThree.attack( "la Macronie");
	scavThree.highFivesGuys();

	return 0;
}