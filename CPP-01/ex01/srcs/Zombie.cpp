/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:23 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 17:05:48 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"
#include "../incs/outputs.h"

Zombie::Zombie()
{

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