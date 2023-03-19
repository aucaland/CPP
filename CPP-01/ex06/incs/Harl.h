/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:09:00 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 15:25:58 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_HARL_H
#define CPP_HARL_H

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Harl
{
private :
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public :
	Harl();
	~Harl();
	void		complain( std::string level );

};


#endif //CPP_HARL_H