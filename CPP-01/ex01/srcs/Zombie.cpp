/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:23 by aurel             #+#    #+#             */
/*   Updated: 2023/04/08 13:51:08 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"
#include "../incs/outputs.h"

Zombie::Zombie()
{
	this->_name = "Default";
	std::cout << this->_name << " Zombie was created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->index << " " << this->_name << ZOMBIE_DEATH <<
	std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ANNOUNCEMENT << std::endl;
}

void	Zombie::setName(string name)
{
	this->_name = name;
}