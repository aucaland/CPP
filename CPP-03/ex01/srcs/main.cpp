/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/04/26 15:19:18 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.h"

int main()
{
//	 Virtual purpose
//	ClapTrap* test3 = new ScavTrap("toto");
//	test3->attack("truc");
//	delete test3;

//	ScavTrap scavOne( "Macron" );
	ScavTrap scavThree( "Benne a ordures");
//	ScavTrap scavTwo(scavThree);
	ScavTrap test;
//
	test = scavThree;
	ScavTrap test2( test );
//	scavOne.attack( "La ZAD de Notre Dame des Landes");
//	scavOne.attack( " les retraites");
//	scavTwo.attack( "Darmanin");
//	scavThree.attack( "la Macronie");
	test.attack("dans le vent");
	test2.attack( "pour rien");
	test2.guardGate();
//	scavThree.attack( "la Macronie");
//
	return 0;
}