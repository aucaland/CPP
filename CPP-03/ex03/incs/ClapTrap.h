/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:30 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/23 01:10:35 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_CLAPTRAP_H
#define CPP_CLAPTRAP_H

#include <iostream>
using std::string;

class ClapTrap {

protected:
	string				_name;
	unsigned int		_hitPoint;
	int 				_energyPoint;
	unsigned int 		_attackDamage;
public :
	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap( string name );
	ClapTrap(const ClapTrap &);
	ClapTrap& operator=(const ClapTrap &);

	virtual void attack( const string& target );
	virtual void takeDamage( unsigned int amount );
	virtual void beRepaired( unsigned int amount );

};


#endif //CPP_CLAPTRAP_H
