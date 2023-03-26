/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:33 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/26 11:42:25 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.h"
#include "../../ex01/incs/Animal.h"


using std::cout;
using std::endl;

Animal::Animal() {
	cout << "Constructor Animal called" << endl;
}

Animal::~Animal() {
	cout << "Destructor Animal called" << endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	cout << "Copy constructor Animal called" << endl;
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	cout << "Constructor assignement Animal called" << endl;
	return *this;
}

void Animal::makeSound() const
{
	cout << ".." << endl;
}

string Animal::getType() const
{
	return this->type;
}





