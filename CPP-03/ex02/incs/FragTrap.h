/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:29:57 by aurel             #+#    #+#             */
/*   Updated: 2023/03/22 11:01:25 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_FRAGTRAP_H
#define CPP_FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public:
	~FragTrap();
	FragTrap( string name );
//	FragTrap( const FragTrap & other );
//	FragTrap& operator=( const FragTrap & );
	void highFivesGuys();
	void attack( const string &target );

	FragTrap();
};

#endif //CPP_FRAGTRAP_H
