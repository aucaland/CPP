/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:13 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 19:30:33 by aurel            ###   ########.fr       */
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
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);

private :
	static const int	_nbrFracBit;
	int					_fixedPoint;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif //CPP_FIXED_H
