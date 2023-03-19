/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:23 by aurel             #+#    #+#             */
/*   Updated: 2023/03/19 14:56:15 by aurel            ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &other) const
{
	cout << "Operator > called" << endl;
	if (this->getRawBits() > other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) const
{
	cout << "Operator < called" << endl;
	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
	cout << "Operator >= called" << endl;
	if (this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
	cout << "Operator <= called" << endl;
	if (this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const
{
	cout << "Operator == called" << endl;
	if (this->getRawBits() == other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
	cout << "Operator != called" << endl;
	if (this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed &Fixed::min(Fixed &fixedOne, Fixed &fixedTwo)
{
	if (fixedOne > fixedTwo)
		return (fixedTwo);
	return (fixedOne);
}

const Fixed &Fixed::min(const Fixed &fixedOne, const Fixed &fixedTwo)
{
	if (fixedOne > fixedTwo)
		return (fixedTwo);
	return (fixedOne);
}

Fixed &Fixed::max(Fixed &fixedOne, Fixed &fixedTwo)
{
	if (fixedOne < fixedTwo)
		return (fixedTwo);
	return (fixedOne);
}

const Fixed &Fixed::max(const Fixed &fixedOne, const Fixed &fixedTwo)
{
	if (fixedOne < fixedTwo)
		return (fixedTwo);
	return (fixedOne);
}

Fixed &Fixed::operator++(void)
{
	++(this->_fixedPoint);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp._fixedPoint++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	--(this->_fixedPoint);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp._fixedPoint--;
	return tmp;
}