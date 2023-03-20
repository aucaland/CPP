/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:19:53 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/20 13:28:43 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.h"

int main()
{
	ClapTrap clap = ClapTrap("Jean-mi");

	clap.attack("George");
	clap.takeDamage(3);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	clap.beRepaired(2);
	return (0);
}