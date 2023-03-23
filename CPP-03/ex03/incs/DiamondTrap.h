//
// Created by aurel on 3/22/23.
//

#ifndef CPP_DIAMONDTRAP_H
# define CPP_DIAMONDTRAP_H


#include <iostream>
#include "FragTrap.h"
#include "ScavTrap.h"

using std::string;


class DiamondTrap : public FragTrap, public ScavTrap
{
private :
	string _name;

public:
	DiamondTrap();

	~DiamondTrap();
	DiamondTrap( string name );
	DiamondTrap &operator=( const DiamondTrap & );

	DiamondTrap( const DiamondTrap & );
	void attack( const string & target );
};

#endif