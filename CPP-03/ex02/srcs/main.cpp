/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/04/26 15:29:44 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.h"

int main()
{

	FragTrap fragOne( "Macron" );
	FragTrap fragThree( "Benne a ordures");
//	FragTrap fragTwo(fragThree);
//	FragTrap test;

//	test = fragTwo;
	fragOne.attack( "La ZAD de Notre Dame des Landes");
	fragOne.attack( " les retraites");
//	fragTwo.attack( "Darmanin");
	fragThree.attack( "la Macronie");
//	test.attack("dans le vent");
	fragThree.attack( "la Macronie");
	fragThree.highFivesGuys();

	return 0;
}