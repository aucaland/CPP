/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:33 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/25 21:58:25 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/WrongAnimal.h"
using std::cout;
using std::endl;

WrongAnimal::WrongAnimal() {
	cout << "Constructor WrongAnimal called" << endl;
}

WrongAnimal::~WrongAnimal() {
	cout << "Destructor WrongAnimal called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	cout << "Copy constructor WrongAnimal called" << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	cout << "Constructor assignement WrongAnimal called" << endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	cout << ".." << endl;
}

string WrongAnimal::getType() const
{
	return this->type;
}