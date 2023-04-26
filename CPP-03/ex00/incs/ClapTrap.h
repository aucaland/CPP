/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:50:30 by aucaland          #+#    #+#             */
/*   Updated: 2023/04/26 15:05:11 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_CLAPTRAP_H
#define CPP_CLAPTRAP_H

#include <iostream>
using std::string;

class ClapTrap {
private :
	string			_name;
	unsigned int	_hitPoint;
	int 			_energyPoint;
	unsigned int 	_attackDamage;

public :
	ClapTrap();
	~ClapTrap();
	ClapTrap( string name );
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
	void attack( const string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

};


#endif //CPP_CLAPTRAP_H
