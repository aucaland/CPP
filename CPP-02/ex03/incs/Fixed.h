/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:13 by aurel             #+#    #+#             */
/*   Updated: 2023/03/19 21:00:20 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_FIXED_H
#define CPP_FIXED_H

#include <iostream>

class Fixed
{
public :
	Fixed();
	~Fixed();
	Fixed( const int x );
	Fixed( const float y );
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed& operator++( void );
	Fixed operator ++( int );
	Fixed& operator--( void );
	Fixed operator --( int );



	float		toFloat( void ) const;
	int			toInt( void ) const;
	int			getRawBits( void ) const;
	void		setRawBits( int const raw);
	static Fixed&	min(Fixed& fixedOne, Fixed& fixedTwo);
	static const Fixed&	min(const Fixed& fixedOne, const Fixed& fixedTwo);
	static Fixed&	max(Fixed& fixedOne, Fixed& fixedTwo);
	static const Fixed&	max(const Fixed& fixedOne, const Fixed& fixedTwo);

private :
	static const int	_nbrFracBit;
	int					_fixedPoint;
};
//std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif //CPP_FIXED_H
