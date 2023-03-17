/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:15 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 17:00:33 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ZOMBIE_H
#define CPP_ZOMBIE_H

#include <iostream>
using std::string;

class Zombie
{
private :
	string	_name;

public :
	Zombie();
	~Zombie();
	int		index;

	void 			announce( void );
	static Zombie*	zombieHorde(int N, string name);
	void			setName( string name );

};


#endif //CPP_ZOMBIE_H
