/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:15 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 14:24:13 by aurel            ###   ########.fr       */
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

	void	_randomChump( string name);

public :
	explicit Zombie(const string& name);
	~Zombie();
	void 	announce( void );
	static Zombie*	newZombie( string name );

};


#endif //CPP_ZOMBIE_H
