/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:23 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 19:33:48 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.h"
#include <iostream>
#include <cmath>

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

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (float)(1 << _nbrFracBit));
}

int Fixed::toInt(void) const
{
	return ((int)this->getRawBits() / (int)(1 << _nbrFracBit));
}

Fixed::Fixed(const float y)
{
	cout << "Float constructor called" << endl;
	this->_fixedPoint = (int)(roundf(y * (1 << _nbrFracBit)));
}

Fixed::Fixed(const int x)
{
	cout << "Int constructor called" << endl;
	this->_fixedPoint = (int)((x * (1 << _nbrFracBit)));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
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
	return this->_fixedPoint;
}
