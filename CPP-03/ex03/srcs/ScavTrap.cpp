/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:39:59 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/24 13:25:11 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.h"
using std::cout;
using std::endl;

ScavTrap::ScavTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	cout << "Constructor \033[1m\033[32mScavTrap\033[0m\033[0m called" << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "Destructor \033[1m\033[32mScavTrap\033[0m\033[0m called" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	cout << "\033[1m\033[32mScavTrap\033[0m\033[0m [ " << this->_name << " ] constructor called" << endl;
}

//ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap( other )
//{
//	cout << "Copy constructor \033[1m\033[32mScavTrap\033[0m\033[0m [ " << this->_name << " ] called" << endl;
//}

//ScavTrap &ScavTrap::operator=(const ScavTrap &other)
//{
//	ClapTrap * ad1, * ad2;
//	ad1 = this;
//	ad2 = (ClapTrap *) &other;
//	*ad1 = *ad2;
//// Dans le cas d'une surdefinition de l'operateur par la classe Scav
//// Utile si l'on doit la redefinir dans le cas de nouveaux attributs.
//	cout << "Constructor assignement Scavtrap called" << endl;
//	return *this;
//}

void ScavTrap::attack(const string &target)
{
	if (this->_energyPoint == 0)
	{
		cout << "No energy point available, attack failed for \033[1m\033[32mScavTrap\033[0m\033[0m: " << this->_name << endl;
		return ;
	}
	this->_energyPoint--;
	cout << "\033[1m\033[32mScavTrap\033[0m\033[0m " << this->_name << " \033[1;31mattacks\033[0m " << target << \
			", causing " << this->_attackDamage << " points of damage! Mana remaining: "<< this->_energyPoint << "\033[0m" << endl;
}

void ScavTrap::guardGate()
{
	cout << "\033[1m\033[32mScavTrap\033[0m\033[0m :" << this->_name << " is in Gate keeper mode" << endl;
}
