/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:33 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/24 15:23:33 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

using std::cout;
using std::endl;

Animal::Animal() {
	cout << "Constructor Animal called" << endl;
}

Animal::~Animal() {
	cout << "Destructor Animal called" << endl;
}

Animal::Animal(const Animal &other) {
	cout << "Copy constructor Animal called" << endl;
}

Animal &Animal::operator=(const Animal &other) {
	cout << "Constructor assignement Animal called" << endl;
	return *this;
}
