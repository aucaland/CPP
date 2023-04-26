/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:30:24 by aurel             #+#    #+#             */
/*   Updated: 2023/03/24 13:35:41 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.h"
using std::cout;
using std::endl;

FragTrap::FragTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	cout << "Constructor \033[1m\033[32mFragTrap\033[0m\033[0m called" << endl;
}

FragTrap::~FragTrap()
{
	cout << "Destructor \033[1m\033[32mFragTrap\033[0m\033[0m called" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	cout << "\033[1m\033[32mFragTrap\033[0m\033[0m [ " << this->_name << " ] constructor called" << endl;
}

//FragTrap::FragTrap(const FragTrap &other) : ClapTrap( other )
//{
//	cout << "Copy constructor \033[1m\033[32mFragTrap\033[0m\033[0m [ " << this->_name << " ] called" << endl;
//}

//FragTrap &FragTrap::operator=(const FragTrap &other)
//{
//	ClapTrap * ad1, * ad2;
//	ad1 = this;
//	ad2 = (ClapTrap *) &other;
//	*ad1 = *ad2;
//// Dans le cas d'une surdefinition de l'operateur par la classe Scav
//// Utile si l'on doit la redefinir dans le cas de nouveaux attributs.
//	cout << "Constructor assignement FragTrap called" << endl;
//	return *this;
//}

void FragTrap::attack(const string &target)
{
	if (this->_energyPoint == 0)
	{
		cout << "No energy point available, attack failed for FragTrap: " << this->_name << endl;
		return ;
	}
	this->_energyPoint--;
	cout << "\033[1m\033[32mFragTrap\033[0m\033[0m " << this->_name << " attacks " << target << \
			", causing " << this->_attackDamage << " points of damage! Mana remaining: "<< this->_energyPoint <<  endl;
}

void FragTrap::highFivesGuys()
{
	cout << "\033[1m\033[32mFragTrap\033[0m\033[0m :" << this->_name << " asks for a High Fives" << endl;
}
