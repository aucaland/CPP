/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:39:59 by aucaland          #+#    #+#             */
/*   Updated: 2023/04/26 15:15:39 by aucaland         ###   ########.fr       */
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
	this->_name = "default";
	cout << "Constructor ScavTrap [ " << this->_name << " ] called" << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "Destructor ScavTrap [ " << this->_name << " ] called" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	cout << "ScavTrap [ " << this->_name << " ] constructor called" << endl;
}

//ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap( other )
//{
//	cout << "Copy constructor ScavTrap [ " << this->_name << " ] called" << endl;
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
//}}

void ScavTrap::attack(const string &target)
{
	if (this->_energyPoint == 0)
	{
		cout << "No energy point available, attack failed for ScavTrap: " << this->_name << endl;
		return ;
	}
	this->_energyPoint--;
	cout << "\033[1mScavTrap " << this->_name << " attacks " << target << \
			", causing " << this->_attackDamage << " points of damage! Mana remaining: "<< this->_energyPoint << "\033[0m" << endl;
}

void ScavTrap::guardGate()
{
	cout << "\033[1mScavTrap :" << this->_name << " is in Gate keeper mode\033[0m" << endl;
}
