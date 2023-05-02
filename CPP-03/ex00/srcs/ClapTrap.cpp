/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:37 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/02 11:08:34 by aucaland         ###   ########.fr       */
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
	cout << "Default constructor Claptrap called" << endl;
}

ClapTrap::~ClapTrap() {
	cout << "Destructeur Claptrap " << this->_name << " called" << endl;
}

ClapTrap::ClapTrap(string name) : _name(name), 	_hitPoint(10),
								_energyPoint(10) ,_attackDamage(1)
{
	cout << "Constructor Claptrap " << this->_name << " called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_attackDamage = other._attackDamage;
	this->_energyPoint = other._energyPoint;
	this->_hitPoint = other._hitPoint;
	this->_name = other._name;
	cout << "Copy constructor Claptrap " << this->_name << " called" << endl;
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
	cout << "Copy assignement Claptrap " << this->_name << " called" << endl;
	return *this;
}

void ClapTrap::attack(const string &target)
{
	if (this->_energyPoint <= 0)
	{
		cout << "No energy point available, attack failed" << endl;
		return ;
	}
	if (this->_hitPoint <= 0)
	{
		cout << "ClapTrap " << this->_name << " is dead" << endl;
		return ;
	}
	this->_energyPoint--;
	cout << "ClapTrap " << this->_name << " attacks " << target << \
			", causing " << this->_attackDamage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint <= 0)
		cout << "ClapTrap " << this->_name << " cannot take damage, he is already dead" << endl;
	this->_hitPoint -= amount;
	if (this->_hitPoint >= 429496729)
		this->_hitPoint = 0;
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
	if (this->_hitPoint <= 0)
	{
		cout << "ClapTrap " << this->_name << " is dead" << endl;
		return ;
	}
	this->_energyPoint--;
	this->_hitPoint += amount;
	cout << "ClapTrap " << this->_name << " repair himself for " << amount << \
			" health, remaining health : " << this->_hitPoint << endl;
}

