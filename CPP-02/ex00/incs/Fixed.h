/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:46:13 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 16:56:15 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_FIXED_H
#define CPP_FIXED_H


class Fixed
{
private :
	int					_fixedPoint;
	static const int	_nbrFracBit;
public :
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
};


#endif //CPP_FIXED_H
