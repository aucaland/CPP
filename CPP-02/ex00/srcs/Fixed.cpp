/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:23 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 17:51:12 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.h"
#include <iostream>

using std::cout;
using std::endl;

const int Fixed::_nbrFracBit = 8;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->_fixedPoint = 0;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed &other)
{
	cout << "Copy constructor called" << endl;
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other)
{
	cout << "Copy assignement operator called" << endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

void Fixed::setRawBits(const int raw)
{
	this->_fixedPoint = raw;
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return this->_fixedPoint;
}
