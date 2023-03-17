/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:38:33 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 19:23:57 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.h"
using std::cout;
using std::endl;

HumanA::HumanA(string name, Weapon& weapon) : _name(name), _weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	cout << this->_name << " attacks with " << this->_weapon.getType() <<
		 endl;
}