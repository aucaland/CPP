/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:39:59 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/20 23:07:17 by aurel            ###   ########.fr       */
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
//	cout << "Constructor assignement Scavtrap called" << endl;
//	this->_name = other._name;
//	this->_energyPoint = other._energyPoint;
//	this->_attackDamage = other._attackDamage;
//	this->_hitPoint = other._hitPoint;
//	return *this;
//}

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
	cout << "ScavTrap :" << this->_name << " is in Gate keeper mode" << endl;
}
