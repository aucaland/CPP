/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:37 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/20 13:37:09 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.h"
using std::cout;
using std::endl;

ClapTrap::ClapTrap()
{
	_name = "";
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 1;
}

ClapTrap::~ClapTrap() {

}

ClapTrap::ClapTrap(string name) : _name(name), 	_hitPoint(10),
								_energyPoint(10) ,_attackDamage(1)
{

}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_attackDamage = other._attackDamage;
	this->_energyPoint = other._energyPoint;
	this->_hitPoint = other._hitPoint;
	this->_name = other._name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_attackDamage = other._attackDamage;
		this->_energyPoint = other._energyPoint;
		this->_hitPoint = other._hitPoint;
		this->_name = other._name;
	}
	return *this;
}

void ClapTrap::attack(const string &target)
{
	if (this->_energyPoint == 0)
	{
		cout << "No energy point available, attack failed" << endl;
		return ;
	}
	this->_energyPoint--;
	cout << "ClapTrap " << this->_name << " attacks " << target << \
			", causing " << this->_attackDamage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoint -= amount;
	cout << "ClapTrap " << this->_name << " take " << amount << \
			" damage, remaining health : " << this->_hitPoint << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoint == 0)
	{
		cout << "No energy point available, repair failed" << endl;
		return ;
	}
	this->_energyPoint--;
	this->_hitPoint += amount;
	cout << "ClapTrap " << this->_name << " repair himself for " << amount << \
			" health, remaining health : " << this->_hitPoint << endl;
}
