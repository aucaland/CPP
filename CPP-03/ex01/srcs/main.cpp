/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/02 11:19:28 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.h"

int main()
{
//	 Virtual purpose
//	ClapTrap* test3 = new ScavTrap("toto");
//	test3->attack("truc");
//	delete test3;

	ScavTrap scavOne( "Bocal" );
	ScavTrap scavTwo( "Le Freeze");
	ScavTrap scavThree( "Le Global Random");
	ScavTrap test;

	test = scavThree;
	ScavTrap test2( test );
	scavTwo.attack( "Le Global Random" );
	scavOne.attack( "Le Freeze");
	scavOne.attack( " Le Tuto cub3d");
	test.attack("Bocal");
	test.attack("dans le vent");
	test2.attack( "pour rien");
	test2.guardGate();

	return 0;
}