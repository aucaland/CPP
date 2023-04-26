/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:39:52 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/22 10:50:50 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_SCAVTRAP_H
#define CPP_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
	~ScavTrap();
	ScavTrap( string name );
//	ScavTrap( const ScavTrap &other );
//	ScavTrap& operator=( const ScavTrap &other );
	void guardGate();
	void attack( const string &target );

	ScavTrap();
};


#endif //CPP_SCAVTRAP_H
