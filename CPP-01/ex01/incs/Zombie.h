/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:15 by aurel             #+#    #+#             */
/*   Updated: 2023/04/18 15:56:21 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ZOMBIE_H
#define CPP_ZOMBIE_H

#include <iostream>
#include <stdlib.h>
using std::string;

class Zombie
{
private :
	int		_index;

	string	_name;
public :
	Zombie();
	~Zombie();

	void 			announce( void );
	static Zombie*	zombieHorde(int N, string name);
	void			setName( string name );
	int 			getIndex();

};


#endif //CPP_ZOMBIE_H
