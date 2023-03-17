/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:23 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 14:24:13 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.h"
#include "../incs/outputs.h"

Zombie::Zombie(const string& name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ZOMBIE_DEATH << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ANNOUNCEMENT << std::endl;
}