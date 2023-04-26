/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/24 15:15:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.h"

int main()
{
//	 Virtual purpose;
//	ClapTrap* test1 = new FragTrap("toto");
//	test1->attack("truc");
//	delete test1;
	DiamondTrap scavOne( "Macron" );
	DiamondTrap scavThree( "Benne a ordures");
	DiamondTrap scavTwo(scavThree);
	DiamondTrap test("toto");
	std::cout << "--------------------------" << std::endl;

	test = scavTwo;
	scavOne.attack( "La ZAD de Notre Dame des Landes");
	scavOne.attack( " les retraites");
	scavTwo.attack( "Darmanin");
	scavThree.attack( "la Macronie");
	test.attack("dans le vent");
	scavThree.attack( "la Macronie");
	scavThree.highFivesGuys();
	scavThree.whoAmI();
	scavOne.whoAmI();
	scavTwo.whoAmI();
	test.whoAmI();
	return 0;
}