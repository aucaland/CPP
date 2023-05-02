/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/02 12:47:55 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.h"

int main()
{
//	 Virtual purpose;
//	ClapTrap* test1 = new FragTrap("toto");
//	test1->attack("truc");
//	delete test1;

	DiamondTrap DiamondOne( "Bocal" );
	DiamondTrap DiamondTwo( "Le Freeze");
	DiamondTrap DiamondThree( "Le Global Random");
	DiamondTrap test ( " Bocal");

	std::cout << "--------------------------" << std::endl;

	test = DiamondThree;
	DiamondTrap test2( test );
	DiamondTwo.attack( "Le Global Random" );
	DiamondOne.attack( "Le Freeze");
	DiamondOne.attack( " Le Tuto cub3d");
	test.attack("Bocal");
	test.attack("dans le vent");
	test2.attack( "pour rien");

	DiamondOne.whoAmI();
	DiamondTwo.whoAmI();
	DiamondThree.whoAmI();
	test.whoAmI();
	return 0;
}