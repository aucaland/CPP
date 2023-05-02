/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/02 11:29:21 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.h"

int main()
{

	FragTrap FragOne( "Bocal" );
	FragTrap FragTwo( "Le Freeze");
	FragTrap FragThree( "Le Global Random");
	FragTrap test;

	test = FragThree;
	FragTrap test2( test );
	FragTwo.attack( "Le Global Random" );
	FragOne.attack( "Le Freeze");
	FragOne.attack( " Le Tuto cub3d");
	test.attack("Bocal");
	test.attack("dans le vent");
	test2.attack( "pour rien");
	FragThree.highFivesGuys();

	return 0;
}